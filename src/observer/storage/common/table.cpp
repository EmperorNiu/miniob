/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2021/5/13.
//

#include <limits.h>
#include <string.h>
#include <algorithm>
#include <sql/executor/tuple.h>
//#include <vector>
#include "storage/common/table.h"
#include "storage/common/table_meta.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/default/disk_buffer_pool.h"
#include "storage/common/record_manager.h"
#include "storage/common/condition_filter.h"
#include "storage/common/meta_util.h"
#include "storage/common/index.h"
#include "storage/common/bplus_tree_index.h"
#include "storage/trx/trx.h"

Table::Table() :
        data_buffer_pool_(nullptr),
        file_id_(-1),
        record_handler_(nullptr) {
}

Table::~Table() {
    delete record_handler_;
    record_handler_ = nullptr;

    if (data_buffer_pool_ != nullptr && file_id_ >= 0) {
        data_buffer_pool_->close_file(file_id_);
        data_buffer_pool_ = nullptr;
    }

    LOG_INFO("Table has been closed: %s", name());
}

RC Table::create(const char *path, const char *name, const char *base_dir, int attribute_count,
                 const AttrInfo attributes[]) {

    if (nullptr == name || common::is_blank(name)) {
        LOG_WARN("Name cannot be empty");
        return RC::INVALID_ARGUMENT;
    }
    LOG_INFO("Begin to create table %s:%s", base_dir, name);

    if (attribute_count <= 0 || nullptr == attributes) {
        LOG_WARN("Invalid arguments. table_name=%s, attribute_count=%d, attributes=%p",
                 name, attribute_count, attributes);
        return RC::INVALID_ARGUMENT;
    }

    RC rc = RC::SUCCESS;

    // 使用 table_name.table记录一个表的元数据
    // 判断表文件是否已经存在

    int fd = ::open(path, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
    if (-1 == fd) {
        if (EEXIST == errno) {
            LOG_ERROR("Failed to create table file, it has been created. %s, EEXIST, %s",
                      path, strerror(errno));
            return RC::SCHEMA_TABLE_EXIST;
        }
        LOG_ERROR("Create table file failed. filename=%s, errmsg=%d:%s",
                  path, errno, strerror(errno));
        return RC::IOERR;
    }

    close(fd);

    // 创建文件
    if ((rc = table_meta_.init(name, attribute_count, attributes)) != RC::SUCCESS) {
        LOG_ERROR("Failed to init table meta. name:%s, ret:%d", name, rc);
        return rc; // delete table file
    }

    std::fstream fs;
    fs.open(path, std::ios_base::out | std::ios_base::binary);
    if (!fs.is_open()) {
        LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", path, strerror(errno));
        return RC::IOERR;
    }

    // 记录元数据到文件中
    table_meta_.serialize(fs);
    fs.close();

    std::string data_file = std::string(base_dir) + "/" + name + TABLE_DATA_SUFFIX;
    data_buffer_pool_ = theGlobalDiskBufferPool();
    rc = data_buffer_pool_->create_file(data_file.c_str());
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to create disk buffer pool of data file. file name=%s", data_file.c_str());
        return rc;
    }

    std::string text_file = std::string(base_dir) + "/" + name + TABLE_TEXT_SUFFIX;
    fd = ::open(text_file.c_str(), O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
    if (fd < 0) {
        LOG_ERROR("Failed to create %s, due to %s.", text_file.c_str(), strerror(errno));
        return RC::SCHEMA_DB_EXIST;
    }
    close(fd);
    if ((fd = ::open(text_file.c_str(), O_RDWR)) >= 0) {
        long_fd_=fd;
    } else {
        LOG_ERROR("Failed to open file %s, because %s.", text_file.c_str(), strerror(errno));
        return RC::IOERR_ACCESS;
    }


    rc = init_record_handler(base_dir);

    base_dir_ = base_dir;
    LOG_INFO("Successfully create table %s:%s", base_dir, name);
    return rc;
}

RC Table::open(const char *meta_file, const char *base_dir) {
    // 加载元数据文件
    std::fstream fs;
    std::string meta_file_path = std::string(base_dir) + "/" + meta_file;
    fs.open(meta_file_path, std::ios_base::in | std::ios_base::binary);
    if (!fs.is_open()) {
        LOG_ERROR("Failed to open meta file for read. file name=%s, errmsg=%s", meta_file, strerror(errno));
        return RC::IOERR;
    }
    if (table_meta_.deserialize(fs) < 0) {
        LOG_ERROR("Failed to deserialize table meta. file name=%s", meta_file);
        return RC::GENERIC_ERROR;
    }
    fs.close();

    // 加载数据文件
    RC rc = init_record_handler(base_dir);

    base_dir_ = base_dir;

    const int index_num = table_meta_.index_num();
    for (int i = 0; i < index_num; i++) {
        const IndexMeta *index_meta = table_meta_.index(i);
        std::vector<std::string> field_names = index_meta->get_fields();
        // 获取索引元信息
        std::vector<const FieldMeta *> field_metas;
        for(int i = 0; i< field_names.size(); i++){
          const FieldMeta *field_meta = table_meta_.field(field_names[i].c_str());
          if(!field_meta){
            return RC::SCHEMA_FIELD_MISSING;
          }
          field_metas.push_back(field_meta);
        }
        if (field_metas.size() == 0){
          return RC::GENERIC_ERROR;
        }
//        const FieldMeta *field_meta = table_meta_.field(index_meta->field());
//        if (field_meta == nullptr) {
//            LOG_PANIC("Found invalid index meta info which has a non-exists field. table=%s, index=%s, field=%s",
//                      name(), index_meta->name(), index_meta->field());
//            return RC::GENERIC_ERROR;
//        }

        BplusTreeIndex *index = new BplusTreeIndex();
        index->setUnique(index_meta->isUnique());
        std::string index_file = index_data_file(base_dir, name(), index_meta->name());
        rc = index->open(index_file.c_str(), *index_meta, field_metas);
        if (rc != RC::SUCCESS) {
            delete index;
            LOG_ERROR("Failed to open index. table=%s, index=%s, file=%s, rc=%d:%s",
                      name(), index_meta->name(), index_file.c_str(), rc, strrc(rc));
            return rc;
        }
        indexes_.push_back(index);
    }
    return rc;
}

RC Table::commit_insert(Trx *trx, const RID &rid) {
    Record record;
    RC rc = record_handler_->get_record(&rid, &record);
    if (rc != RC::SUCCESS) {
        return rc;
    }

    return trx->commit_insert(this, record);
}

RC Table::rollback_insert(Trx *trx, const RID &rid) {

    Record record;
    RC rc = record_handler_->get_record(&rid, &record);
    if (rc != RC::SUCCESS) {
        return rc;
    }

    // remove all indexes
    rc = delete_entry_of_indexes(record.data, rid, false);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to delete indexes of record(rid=%d.%d) while rollback insert, rc=%d:%s",
                  rid.page_num, rid.slot_num, rc, strrc(rc));
    } else {
        rc = record_handler_->delete_record(&rid);
    }
    return rc;
}

RC Table::insert_record(Trx *trx, Record *record) {
    RC rc = RC::SUCCESS;

    if (trx != nullptr) {
        trx->init_trx_info(this, *record);
    }

    rc = record_handler_->insert_record(record->data, table_meta_.record_size(), &record->rid);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Insert record failed. table name=%s, rc=%d:%s", table_meta_.name(), rc, strrc(rc));
        return rc;
    }

    if (trx != nullptr) {
        rc = trx->insert_record(this, record);
        if (rc != RC::SUCCESS) {
            LOG_ERROR("Failed to log operation(insertion) to trx");

            RC rc2 = record_handler_->delete_record(&record->rid);
            if (rc2 != RC::SUCCESS) {
                LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
                          name(), rc2, strrc(rc2));
            }
            return rc;
        }
    }

    rc = insert_entry_of_indexes(record->data, record->rid);
    if (rc != RC::SUCCESS) {
        RC rc2 = delete_entry_of_indexes(record->data, record->rid, false);
        if (rc2 != RC::SUCCESS) {
            LOG_PANIC("Failed to rollback index data when insert index entries failed. table name=%s, rc=%d:%s",
                      name(), rc2, strrc(rc2));
        }

        rc2 = record_handler_->delete_record(&record->rid);
        if (rc2 != RC::SUCCESS) {
            LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
                      name(), rc2, strrc(rc2));
        }
        if (trx != nullptr) {
            trx->delete_record(this, record);
        }
        return rc;
    }
    return rc;
}

RC Table::insert_record(Trx *trx, int value_num, const Value *values, int insert_num) {
    if (value_num <= 0 || nullptr == values || insert_num <= 0) {
        LOG_ERROR("Invalid argument. value num=%d, values=%p", value_num, values);
        return RC::INVALID_ARGUMENT;
    }
    char *record_data;
    int value_length = value_num / insert_num;
    Record *r = new Record[insert_num];
    for (int i = 0; i < insert_num; ++i) {
        Value *a = new Value[value_length];
        for (int j = 0; j < value_length; ++j) {
            a[j] = values[i * value_length + j];
        }
//        memcpy(a,values+i*value_length,value_length);
        RC rc = make_record(value_length, a, record_data);
        if (rc != RC::SUCCESS) {
            for (int k = 0; k < i; ++k) {
                record_handler_->delete_record(&r[k].rid);
            }
            LOG_ERROR("Failed to create a record. rc=%d:%s", rc, strrc(rc));
            return rc;
        }
        Record record;
        record.data = record_data;
        rc = insert_record(trx, &record);
//        memcpy(r+sizeof(record)*i,&record,sizeof(record));
        r[i] = record;
//        delete[] record_data;
        if (rc != RC::SUCCESS) {
            for (int k = 0; k < i; ++k) {
                record_handler_->delete_record(&r[k].rid);
            }
            LOG_ERROR("Failed to create a record. rc=%d:%s", rc, strrc(rc));
            return rc;
        }
    }
    for (int i = 0; i < insert_num; ++i) {
        delete[] r[i].data;
    }
    // record.valid = true;
    return RC::SUCCESS;
}

const char *Table::name() const {
    return table_meta_.name();
}

const TableMeta &Table::table_meta() const {
    return table_meta_;
}

RC Table:: make_record(int value_num, const Value *values, char *&record_out) {
    // 检查字段类型是否一致
    if (value_num + table_meta_.sys_field_num() != table_meta_.field_num()) {
        return RC::SCHEMA_FIELD_MISSING;
    }

    const int normal_field_start_index = table_meta_.sys_field_num();
    const FieldMeta *nullsmapField = table_meta_.field(1);
    unsigned int nullsmap = 0;
    for (int i = 0; i < value_num; i++) {
        const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
        const Value &value = values[i];
        if (value.type==NULLS){
            if(!field->nullable()) return RC::SCHEMA_FIELD_TYPE_MISMATCH;
            nullsmap = nullsmap | (1<<i);
        }else if (field->type() != value.type) {
            LOG_ERROR("Invalid value type. field name=%s, type=%d, but given=%d",
                      field->name(), field->type(), value.type);
            return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
    }

    // 复制所有字段的值
    int record_size = table_meta_.record_size();
    char *record = new char[record_size];
    memcpy(record + nullsmapField->offset(), &nullsmap, nullsmapField->len());
    for (int i = 0; i < value_num; i++) {
        const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
        const Value &value = values[i];
        if(field->is_text()){
            long file_len = ::lseek(long_fd_,0L,SEEK_END);
            if (write(long_fd_,value.data, 4096) != 4096) {
                LOG_ERROR("Failed to write header to file, due to %s.", strerror(errno));
                return RC::IOERR_WRITE;
            }
            memcpy(record + field->offset(), &file_len, field->len());
            continue;
        }
        memcpy(record + field->offset(), value.data, field->len());
    }

    record_out = record;
    return RC::SUCCESS;
}

RC Table::change_record(const char *attribute, const Value *v, Record *record) {
    const int normal_field_start_index = table_meta_.sys_field_num();
    int null_bitmap = *(int *)(record->data+4);
    for (int i = 0; i < table_meta_.field_num() - normal_field_start_index; i++) {
        const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
        if (strcmp(field->name(), attribute) == 0) {
//      memcpy(record->data + field->offset(), v->data, field->len());
            if (field->type() == INTS && v->type == FLOATS) {
//        int tmp = (int)(*(float*)(v + sizeof(int)));
                int t = (int) (*(float *) v->data);
                memcpy(record->data + field->offset(), &t, field->len());
            } else if (field->type() == FLOATS && v->type == INTS) {
                float t = (float) (*(int *) v->data);
                memcpy(record->data + field->offset(), &t, field->len());
            } else if (field->is_text()){
                long pos = *(long*)(record->data+field->offset());
                lseek(long_fd_,pos,SEEK_SET);
                write(long_fd_,(char *)v->data,4096);
            }else {
                memcpy(record->data + field->offset(), v->data, field->len());
            }
            if (v->type==NULLS) null_bitmap = null_bitmap|(1<<i);
            else null_bitmap = null_bitmap&((~1)<<i);
            memcpy(record->data+4,&null_bitmap,4);
        }
    }
    return RC::SUCCESS;
}

RC Table::init_record_handler(const char *base_dir) {
    std::string data_file = std::string(base_dir) + "/" + table_meta_.name() + TABLE_DATA_SUFFIX;
    std::string text_file = std::string(base_dir) + "/" + table_meta_.name() + TABLE_TEXT_SUFFIX;
    if (nullptr == data_buffer_pool_) {
        data_buffer_pool_ = theGlobalDiskBufferPool();
    }

    int data_buffer_pool_file_id;
    RC rc = data_buffer_pool_->open_file(data_file.c_str(), &data_buffer_pool_file_id);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to open disk buffer pool for file:%s. rc=%d:%s",
                  data_file.c_str(), rc, strrc(rc));
        return rc;
    }

    record_handler_ = new RecordFileHandler();
    rc = record_handler_->init(*data_buffer_pool_, data_buffer_pool_file_id);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to init record handler. rc=%d:%s", rc, strrc(rc));
        return rc;
    }

    file_id_ = data_buffer_pool_file_id;
    int fd;
    if ((fd = ::open(text_file.c_str(), O_RDWR)) >= 0) {
        long_fd_ = fd;
    } else {
        LOG_ERROR("Failed to open file %s, because %s.", text_file.c_str(), strerror(errno));
        return RC::IOERR_ACCESS;
    }

    return rc;
}

/**
 * 为了不把Record暴露出去，封装一下
 */
class RecordReaderScanAdapter {
public:
    explicit RecordReaderScanAdapter(void (*record_reader)(const char *data, void *context), void *context)
            : record_reader_(record_reader), context_(context) {
    }

    void consume(const Record *record) {
        record_reader_(record->data, context_);
    }

private:
    void (*record_reader_)(const char *, void *);

    void *context_;
};

static RC scan_record_reader_adapter(Record *record, void *context) {
    RecordReaderScanAdapter &adapter = *(RecordReaderScanAdapter *) context;
    adapter.consume(record);
    return RC::SUCCESS;
}

RC Table::scan_record(Trx *trx, ConditionFilter *filter, int limit, void *context,
                      void (*record_reader)(const char *data, void *context)) {
    RecordReaderScanAdapter adapter(record_reader, context);
    return scan_record(trx, filter, limit, (void *) &adapter, scan_record_reader_adapter);
}

RC Table::scan_record(Trx *trx, ConditionFilter *filter, int limit, void *context,
                      RC (*record_reader)(Record *record, void *context)) {
    if (nullptr == record_reader) {
        return RC::INVALID_ARGUMENT;
    }

    if (0 == limit) {
        return RC::SUCCESS;
    }

    if (limit < 0) {
        limit = INT_MAX;
    }

    IndexScanner *index_scanner = find_index_for_scan(filter);

    // if (typeid(*context).name() == typeid(TupleRecordAggregateGroupByConverter).name())
    if (index_scanner != nullptr) {
        return scan_record_by_index(trx, index_scanner, filter, limit, context, record_reader);
    }

    RC rc = RC::SUCCESS;
    RecordFileScanner scanner;
    rc = scanner.open_scan(*data_buffer_pool_, file_id_, filter);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("failed to open scanner. file id=%d. rc=%d:%s", file_id_, rc, strrc(rc));
        return rc;
    }

    int record_count = 0;
    Record record;
    rc = scanner.get_first_record(&record);
    for (; RC::SUCCESS == rc && record_count < limit; rc = scanner.get_next_record(&record)) {
        if (trx == nullptr || trx->is_visible(this, &record)) {
            rc = record_reader(&record, context);
            if (rc != RC::SUCCESS) {
                break;
            }
            record_count++;
        }
    }

    if (RC::RECORD_EOF == rc) {
        rc = RC::SUCCESS;
    } else {
        LOG_ERROR("failed to scan record. file id=%d, rc=%d:%s", file_id_, rc, strrc(rc));
    }
    scanner.close_scan();
    return rc;
}

RC Table::scan_record_by_index(Trx *trx, IndexScanner *scanner, ConditionFilter *filter, int limit, void *context,
                               RC (*record_reader)(Record *, void *)) {
    RC rc = RC::SUCCESS;
    RID rid;
    Record record;
    int record_count = 0;
    while (record_count < limit) {
        rc = scanner->next_entry(&rid);
        if (rc != RC::SUCCESS) {
            if (RC::RECORD_EOF == rc || RC::RECORD_NO_MORE_IDX_IN_MEM==rc) {
                rc = RC::SUCCESS;
                break;
            }
            LOG_ERROR("Failed to scan table by index. rc=%d:%s", rc, strrc(rc));
            break;
        }

        rc = record_handler_->get_record(&rid, &record);
        if (rc != RC::SUCCESS) {
            LOG_ERROR("Failed to fetch record of rid=%d:%d, rc=%d:%s", rid.page_num, rid.slot_num, rc, strrc(rc));
            break;
        }

        if ((trx == nullptr || trx->is_visible(this, &record)) && (filter == nullptr || filter->filter(record))) {
            rc = record_reader(&record, context);
            if (rc != RC::SUCCESS) {
                LOG_TRACE("Record reader break the table scanning. rc=%d:%s", rc, strrc(rc));
                break;
            }
        }

        record_count++;
    }

    scanner->destroy();
    return rc;
}

class IndexInserter {
public:
    explicit IndexInserter(Index *index, int isUnique) : index_(index), isUnique_(isUnique) {
    }

    RC insert_index(const Record *record) {
      std::vector<FieldMeta> fieldMetas = index_->field_metas();
      int max_size = 0;
      for(auto & field : fieldMetas){
        max_size += field.len();
      }
      char r[max_size];
      int offset = 0;
      for(auto & field_meta : fieldMetas){
        memcpy(r + offset, record->data + field_meta.offset(), field_meta.len());
        offset += field_meta.len();
      }
        RC rc = index_->insert_entry(r, &record->rid);
        if (rc == RC::SUCCESS) {
            if (isUnique_) {
              const FieldMeta fieldMeta = index_->field_meta();
                if (fieldMeta.type() == INTS || fieldMeta.type() == DATES) {
                    int data;
                    memcpy(&data, record->data + fieldMeta.offset(), fieldMeta.len());
                    if (unique_int.count(data) == 0) unique_int.insert(data);
                    else return RC::SCHEMA_INDEX_EXIST;
                } else if (fieldMeta.type() == FLOATS) {
                    float data;
                    memcpy(&data, record->data + fieldMeta.offset(), fieldMeta.len());
                    if (unique_float.count(data) == 0) unique_float.insert(data);
                    else return RC::SCHEMA_INDEX_EXIST;
                } else if (fieldMeta.type() == CHARS) {
                    std::string data;
                    memcpy(&data, record->data + fieldMeta.offset(), fieldMeta.len());
                    if (unique_string.count(data) == 0) unique_string.insert(data);
                    else return RC::SCHEMA_INDEX_EXIST;
                }
            }
        }
        return rc;
    }

private:
    Index *index_;
    int isUnique_;
    std::set<int> unique_int;
    std::set<float> unique_float;
    std::set<std::string> unique_string;
};

static RC insert_index_record_reader_adapter(Record *record, void *context) {
    IndexInserter &inserter = *(IndexInserter *) context;
    return inserter.insert_index(record);
}

RC Table::create_index(Trx *trx, const char *index_name, char *attribute_names[], int attr_num, int isUnique) {
  // 数据校验
  if (index_name == nullptr || common::is_blank(index_name) ||
      attribute_names == nullptr) {
    return RC::INVALID_ARGUMENT;
  }
  for (int i = 0; i < attr_num; ++i) {
    if (common::is_blank(attribute_names[i])) {
      return RC::INVALID_ARGUMENT;
    }
  }
  if (table_meta_.index(index_name) != nullptr){
    return RC::SCHEMA_INDEX_EXIST;
  }

  // 获取索引元信息
  std::vector<const FieldMeta *> field_metas;
  for(int i = 0; i< attr_num; i++){
    if(attribute_names[i] == nullptr || common::is_blank(attribute_names[i])){
      return RC::INVALID_ARGUMENT;
    }
    const FieldMeta *field_meta = table_meta_.field(attribute_names[i]);
    if(!field_meta){
      return RC::SCHEMA_FIELD_MISSING;
    }
    field_metas.push_back(field_meta);
  }
  if(table_meta_.find_index_by_field(field_metas)){
    return RC::SCHEMA_INDEX_EXIST;
  }

  IndexMeta new_index_meta;
  RC rc = new_index_meta.init(index_name, field_metas, isUnique);
  if (rc != RC::SUCCESS) {
      return rc;
  }

  // 创建索引相关数据
  BplusTreeIndex *index = new BplusTreeIndex();
  std::string index_file = index_data_file(base_dir_.c_str(), name(), index_name);
  rc = index->create(index_file.c_str(), new_index_meta, field_metas);
  index->setUnique(isUnique);
  if (rc != RC::SUCCESS) {
      delete index;
      LOG_ERROR("Failed to create bplus tree index. file name=%s, rc=%d:%s", index_file.c_str(), rc, strrc(rc));
      return rc;
  }

    // 遍历当前的所有数据，插入这个索引
    IndexInserter index_inserter(index, isUnique);
    rc = scan_record(trx, nullptr, -1, &index_inserter, insert_index_record_reader_adapter);
    if (rc != RC::SUCCESS) {
        // rollback
        delete index;
        LOG_ERROR("Failed to insert index to all records. table=%s, rc=%d:%s", name(), rc, strrc(rc));
        return rc;
    }
    indexes_.push_back(index);

    TableMeta new_table_meta(table_meta_);
    rc = new_table_meta.add_index(new_index_meta);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to add index (%s) on table (%s). error=%d:%s", index_name, name(), rc, strrc(rc));
        return rc;
    }
    // 创建元数据临时文件
    std::string tmp_file = table_meta_file(base_dir_.c_str(), name()) + ".tmp";
    std::fstream fs;
    fs.open(tmp_file, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
    if (!fs.is_open()) {
        LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", tmp_file.c_str(), strerror(errno));
        return RC::IOERR; // 创建索引中途出错，要做还原操作
    }
    if (new_table_meta.serialize(fs) < 0) {
        LOG_ERROR("Failed to dump new table meta to file: %s. sys err=%d:%s", tmp_file.c_str(), errno, strerror(errno));
        return RC::IOERR;
    }
    fs.close();

    // 覆盖原始元数据文件
    std::string meta_file = table_meta_file(base_dir_.c_str(), name());
    int ret = rename(tmp_file.c_str(), meta_file.c_str());
    if (ret != 0) {
        LOG_ERROR(
                "Failed to rename tmp meta file (%s) to normal meta file (%s) while creating index (%s) on table (%s). " \
              "system error=%d:%s", tmp_file.c_str(), meta_file.c_str(), index_name, name(), errno, strerror(errno));
        return RC::IOERR;
    }

    table_meta_.swap(new_table_meta);

    LOG_INFO("add a new index (%s) on the table (%s)", index_name, name());

    return rc;
}

class RecordUpdater {
public:
    RecordUpdater(Table &table, Trx *trx, const char *attribute, const Value *v) : table_(table),
                                                                                   trx_(trx),
                                                                                   attribute_name_(attribute),
                                                                                   value_(v) {
    }

    RC update_record(Record *record) {
        RC rc = RC::SUCCESS;
        rc = table_.update_record(trx_, record, attribute_name_, value_);
        if (rc == RC::SUCCESS) {
            updated_count_++;
        }
        return rc;
    }

    int updated_count() const {
        return updated_count_;
    }

private:
    Table &table_;
    Trx *trx_;
    int updated_count_ = 0;
    const char *attribute_name_;
    const Value *value_;

};

static RC record_reader_update_adapter(Record *record, void *context) {
    RecordUpdater &record_updater = *(RecordUpdater *) context;
    return record_updater.update_record(record);
}

RC Table::update_record(Trx *trx, const char *attribute_name, const Value *value, int condition_num,
                        const Condition conditions[], int *updated_count) {
    RC rc;
    CompositeConditionFilter condition_filter;
    rc = condition_filter.init(*this, conditions, condition_num);
    if (rc != RC::SUCCESS) {
        return rc;
    }
    if (table_meta_.field(attribute_name) == nullptr) {
        return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    int field_type_compare_compatible_table[5][5] = {
            1, 0, 0, 0, 0,
            0, 1, 0, 0, 0,
            0, 0, 1, 1, 0,
            0, 0, 1, 1, 0,
            0, 0, 0, 0, 1
    };

    if (!field_type_compare_compatible_table[value->type][table_meta_.field(attribute_name)->type()]) {
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
//  if (value->type != table_meta_.field(attribute_name)->type()) {
//    return RC::INVALID_ARGUMENT;
//  }
    RecordUpdater updater(*this, trx, attribute_name, value);
//  Record rc_new = Record();
    rc = scan_record(trx, &condition_filter, -1, &updater, record_reader_update_adapter);
    if (updated_count != nullptr) {
        *updated_count = updater.updated_count();
    }
    return rc;
}

RC Table::update_record(Trx *trx, Record *record, const char *attribute_name, const Value *value) {
    RC rc = RC::SUCCESS;
//  if (trx != nullptr) {
//    rc = trx->update_record(this, record);
//  } else {
//  rc = delete_entry_of_indexes(record->data, record->rid, false);
//  if (rc != RC::SUCCESS) {
//    LOG_ERROR("Failed to delete indexes of record (rid=%d.%d). rc=%d:%s",
//              record->rid.page_num, record->rid.slot_num, rc, strrc(rc));
//  } else {
//  }
//  }
    rc = delete_entry_of_indexes(record->data, record->rid, false);
    if (rc != RC::SUCCESS) {
        return rc;
    }
    change_record(attribute_name, value, record);
    rc = record_handler_->update_record(record);
    if (rc != RC::SUCCESS) {
        return rc;
    }
    rc = insert_entry_of_indexes(record->data, record->rid);
    if (rc != RC::SUCCESS) {
        return rc;
    }
//  rc = update_entry_of_indexes(record->data, record->rid);
    return rc;
}


class RecordDeleter {
public:
    RecordDeleter(Table &table, Trx *trx) : table_(table), trx_(trx) {
    }

    RC delete_record(Record *record) {
        RC rc = RC::SUCCESS;
        rc = table_.delete_record(trx_, record);
        if (rc == RC::SUCCESS) {
            deleted_count_++;
        }
        return rc;
    }

    int deleted_count() const {
        return deleted_count_;
    }

private:
    Table &table_;
    Trx *trx_;
    int deleted_count_ = 0;
};

static RC record_reader_delete_adapter(Record *record, void *context) {
    RecordDeleter &record_deleter = *(RecordDeleter *) context;
    return record_deleter.delete_record(record);
}

RC Table::delete_record(Trx *trx, ConditionFilter *filter, int *deleted_count) {
    RecordDeleter deleter(*this, trx);
    RC rc = scan_record(trx, filter, -1, &deleter, record_reader_delete_adapter);
    if (deleted_count != nullptr) {
        *deleted_count = deleter.deleted_count();
    }
    return rc;
}

RC Table::delete_record(Trx *trx, Record *record) {
    RC rc = RC::SUCCESS;
    if (trx != nullptr) {
        rc = trx->delete_record(this, record);
    } else {
        rc = delete_entry_of_indexes(record->data, record->rid, false);// 重复代码 refer to commit_delete
        if (rc != RC::SUCCESS) {
            LOG_ERROR("Failed to delete indexes of record (rid=%d.%d). rc=%d:%s",
                      record->rid.page_num, record->rid.slot_num, rc, strrc(rc));
        } else {
            rc = record_handler_->delete_record(&record->rid);
        }
    }
    return rc;
}

RC Table::commit_delete(Trx *trx, const RID &rid) {
    RC rc = RC::SUCCESS;
    Record record;
    rc = record_handler_->get_record(&rid, &record);
    if (rc != RC::SUCCESS) {
        return rc;
    }
    rc = delete_entry_of_indexes(record.data, record.rid, false);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to delete indexes of record(rid=%d.%d). rc=%d:%s",
                  rid.page_num, rid.slot_num, rc, strrc(rc));// panic?
    }

    rc = record_handler_->delete_record(&rid);
    if (rc != RC::SUCCESS) {
        return rc;
    }

    return rc;
}

RC Table::rollback_delete(Trx *trx, const RID &rid) {
    RC rc = RC::SUCCESS;
    Record record;
    rc = record_handler_->get_record(&rid, &record);
    if (rc != RC::SUCCESS) {
        return rc;
    }

    return trx->rollback_delete(this, record); // update record in place
}

RC Table::insert_entry_of_indexes(const char *record, const RID &rid) {
    RC rc = RC::SUCCESS;
    for (Index *index: indexes_) {
      if (index->isUnique()) {
        FieldMeta f = index->field_meta();
        char data[f.len()];
//        char *data = new char(f.len());
        memcpy(data,record+f.offset(),f.len());
        IndexScanner *scanner = index->create_scanner(EQUAL_TO, data);
        RID rid_n;
        rc = scanner->next_entry(&rid_n);
        if (rc != RC::SUCCESS) {
          if (RC::RECORD_EOF == rc || RC::RECORD_NO_MORE_IDX_IN_MEM == rc) {
            char data[f.len()];
            memcpy(data,record+f.offset(),f.len());
            rc = index->insert_entry(data, &rid);
            if (rc != RC::SUCCESS) {
              return rc;
            }
          } else return rc;
        }
        else
          return RC::SCHEMA_INDEX_EXIST;
      }
      else {
        std::vector<FieldMeta> fieldmetas = index->field_metas();
        char r[table_meta_.record_size()];
        int offset = 0;
        for(auto & field_meta : fieldmetas){
          memcpy(r + offset, record + field_meta.offset(), field_meta.len());
          offset += field_meta.len();
        }
        rc = index->insert_entry(r, &rid);
        if (rc != RC::SUCCESS) {
            break;
        }
      }
    }
    return rc;
}

RC Table::update_entry_of_indexes(const char *record, const RID &rid) {
    RC rc = RC::SUCCESS;
    for (Index *index: indexes_) {

        rc = index->delete_entry(record, &rid);
        if (rc != RC::SUCCESS) {
            return rc;
        }

        rc = index->insert_entry(record, &rid);
        if (rc != RC::SUCCESS) {
            break;
        }
    }
    return rc;
}

RC Table::delete_entry_of_indexes(const char *record, const RID &rid, bool error_on_not_exists) {
    RC rc = RC::SUCCESS;
    for (Index *index: indexes_) {
      std::vector<FieldMeta> fieldmetas = index->field_metas();
      char r[table_meta_.record_size()];
      int offset = 0;
      for(auto & field_meta : fieldmetas){
        memcpy(r + offset, record + field_meta.offset(), field_meta.len());
        offset += field_meta.len();
      }
        rc = index->delete_entry(r, &rid);
        if (rc != RC::SUCCESS) {
            if (rc != RC::RECORD_INVALID_KEY || !error_on_not_exists) {
                break;
            }
        }
    }
    return rc;
}

Index *Table::find_index(const char *index_name) const {
    for (Index *index: indexes_) {
        if (0 == strcmp(index->index_meta().name(), index_name)) {
            return index;
        }
    }
    return nullptr;
}

IndexScanner *Table::find_index_for_scan(const DefaultConditionFilter &filter) {
    const ConDesc *field_cond_desc = nullptr;
    const ConDesc *value_cond_desc = nullptr;

    // if(filter.comp_op()==EQUAL_IS||filter.comp_op()==EQUAL_IS_NOT) return nullptr;
    if (filter.left().is_attr && !filter.right().is_attr) {
        field_cond_desc = &filter.left();
        value_cond_desc = &filter.right();
    } else if (filter.right().is_attr && !filter.left().is_attr) {
        field_cond_desc = &filter.right();
        value_cond_desc = &filter.left();
    }
    if (field_cond_desc == nullptr || value_cond_desc == nullptr) {
        return nullptr;
    }

    const FieldMeta *field_meta = table_meta_.find_field_by_offset(field_cond_desc->attr_offset);
    if (nullptr == field_meta) {
        LOG_PANIC("Cannot find field by offset %d. table=%s",
                  field_cond_desc->attr_offset, name());
        return nullptr;
    }

    const IndexMeta *index_meta = table_meta_.find_index_by_field(field_meta->name());
    if (nullptr == index_meta) {
        return nullptr;
    }

    Index *index = find_index(index_meta->name());
    if (nullptr == index) {
        return nullptr;
    }

    return index->create_scanner(filter.comp_op(), (const char *) value_cond_desc->value);
}

IndexScanner *Table::find_index_for_scan_multi(const ConditionFilter *filter){
  const CompositeConditionFilter *composite = dynamic_cast<const CompositeConditionFilter *>(filter);
  if(composite == nullptr){
    return nullptr;
  }
  char target_s[table_meta_.record_size()];


  Index * target_index = nullptr;
  CompOp target_op = EQUAL_TO;
  //目前支持两种情况
  //单列索引，支持<，>，。。。。
  //多列索引，只支持======
  for(Index *index : indexes_){
    //最长前缀能否匹配
    //匹配的前缀个数
    std::vector<FieldMeta> fields = index->field_metas();
    int i;
    int offset = 0;
    char s[table_meta_.record_size()];
    CompOp op ;
    bool succ = false;
    for(i = 0; i < fields.size(); i++){
      FieldMeta &field = fields[i];

      int j;
      for(j = 0; j < composite->filter_num(); j++){
        const DefaultConditionFilter * deffilter = dynamic_cast<const DefaultConditionFilter *>
        (&(composite->filter(j)));
        const ConDesc *field_cond_desc = nullptr;
        const ConDesc *value_cond_desc = nullptr;
        if (deffilter->left().is_attr && !deffilter->right().is_attr) {//一边值，一边属性
          field_cond_desc = &deffilter->left();
          value_cond_desc = &deffilter->right();
        } else if (deffilter->right().is_attr && !deffilter->left().is_attr) {
          field_cond_desc = &deffilter->right();
          value_cond_desc = &deffilter->left();
        }
        if (field_cond_desc->attr_offset != field.offset() || field_cond_desc == nullptr || value_cond_desc == nullptr) {
          continue;
        }

        if(deffilter->comp_op() == EQUAL_TO){//find it
          memcpy(s + offset, value_cond_desc->value, field_cond_desc->attr_length);
          offset += field_cond_desc->attr_length;
          op = deffilter->comp_op();
          break;
        }else if(deffilter->comp_op() != NOT_EQUAL && deffilter->comp_op() <= GREAT_THAN){
          memcpy(s + offset, value_cond_desc->value, field_cond_desc->attr_length);
          offset += field_cond_desc->attr_length;
          op = deffilter->comp_op();
          break;
        }
      }
      if(j == composite->filter_num()){//没找到
        break;
      }else{
        if(op == EQUAL_TO){

        }else{
          if(i == 0){//只有一个，可以不为等于号
            i++;
          }
          break;
        }
      }
    }

    //寻找最优的索引
    //目前两种情况，单索引
    //多列==查找索引
    if(i == fields.size()){
      target_index = index;
      target_op = op;
      memcpy(target_s, s, sizeof(s));
      break;
    }

  }

  if(target_index == nullptr){
    return nullptr;
  }else{
    return target_index->create_scanner(target_op, target_s);
  }
}

//IndexScanner *Table::find_index_for_scan(const ConditionFilter *filter) {
//  if (nullptr == filter) {
//    return nullptr;
//  }
//
//  IndexScanner *scanner= find_index_for_scan_multi(filter);
//  if (scanner != nullptr) {
//    return scanner;
//  }
//
//  return nullptr;
//}

IndexScanner *Table::find_index_for_scan(const ConditionFilter *filter) {
    if (nullptr == filter) {
        return nullptr;
    }
//    int flag = 0;
//    for (int i = 0; i < indexes_.size(); ++i) {
//      if (indexes_[i]->isUnique()){
//        flag = 1;
//      }
//    }
//    if (flag == 1) return find_index_for_scan_multi(filter);
    if (!filter->isIn()){
      // remove dynamic_cast
      const DefaultConditionFilter *default_condition_filter = dynamic_cast<const DefaultConditionFilter *>(filter);
      if (default_condition_filter != nullptr) {
        return find_index_for_scan(*default_condition_filter);
      }
    }

    const CompositeConditionFilter *composite_condition_filter = dynamic_cast<const CompositeConditionFilter *>(filter);
    if (composite_condition_filter != nullptr) {
        int filter_num = composite_condition_filter->filter_num();
        for (int i = 0; i < filter_num; i++) {
            IndexScanner *scanner = find_index_for_scan(&composite_condition_filter->filter(i));
            if (scanner != nullptr) {
                return scanner; // 可以找到一个最优的，比如比较符号是=
            }
        }
    }
    return nullptr;
}

RC Table::sync() {
    RC rc = data_buffer_pool_->flush_all_pages(file_id_);
    if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to flush table's data pages. table=%s, rc=%d:%s", name(), rc, strrc(rc));
        return rc;
    }

    for (Index *index: indexes_) {
        rc = index->sync();
        if (rc != RC::SUCCESS) {
            LOG_ERROR("Failed to flush index's pages. table=%s, index=%s, rc=%d:%s",
                      name(), index->index_meta().name(), rc, strrc(rc));
            return rc;
        }
    }
    LOG_INFO("Sync table over. table=%s", name());
    return rc;
}

const int Table::get_long_fd() const {
    return long_fd_;
}
