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
// Created by Wangyunlai on 2021/5/14.
//

#include "sql/executor/tuple.h"
#include "storage/common/table.h"
#include "common/log/log.h"
#include <algorithm>

Tuple::Tuple(const Tuple &other) {
//  LOG_PANIC("Copy constructor of tuple is not supported");
  values_ = (std::move(other.values_));
//  exit(1);
}

Tuple::Tuple(Tuple &&other) noexcept : values_(std::move(other.values_)) {
}

Tuple & Tuple::operator=(Tuple &&other) noexcept {
  if (&other == this) {
    return *this;
  }

  values_.clear();
  values_.swap(other.values_);
  return *this;
}

Tuple::~Tuple() {
}

// add (Value && value)
void Tuple::add(TupleValue *value) {
  values_.emplace_back(value);
}

void Tuple::add(const std::shared_ptr<TupleValue> &other) {
  values_.emplace_back(other);
}

void Tuple::add(int value) {
  add(new IntValue(value));
}

void Tuple::add(float value) {
  add(new FloatValue(value));
}

void Tuple::add(const char *s, int len) {
  add(new StringValue(s, len));
}

////////////////////////////////////////////////////////////////////////////////

std::string TupleField::to_string() const {
  return std::string(table_name_) + "." + field_name_ + std::to_string(type_);
}

////////////////////////////////////////////////////////////////////////////////
void TupleSchema::from_table(const Table *table, TupleSchema &schema) {
  const char *table_name = table->name();
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = 0; i < field_num; i++) {
    const FieldMeta *field_meta = table_meta.field(i);
    if (field_meta->visible()) {
      schema.add(field_meta->type(), table_name, field_meta->name());
    }
  }
}

void TupleSchema::add(AttrType type, const char *table_name, const char *field_name) {
  fields_.emplace_back(type, table_name, field_name);
}

void TupleSchema::add(AttrType type, const char *table_name, const char *field_name,int isAgg) {
  fields_.emplace_back(type, table_name, field_name,isAgg);
}


void TupleSchema::add_if_not_exists(AttrType type, const char *table_name, const char *field_name) {
  for (const auto &field: fields_) {
    if (0 == strcmp(field.table_name(), table_name) &&
        0 == strcmp(field.field_name(), field_name)) {
      return;
    }
  }

  add(type, table_name, field_name);
}

void TupleSchema::append(const TupleSchema &other) {
  fields_.reserve(fields_.size() + other.fields_.size());
  for (const auto &field: other.fields_) {
    fields_.emplace_back(field);
  }
}

int TupleSchema::index_of_field(const char *table_name, const char *field_name) const {
  const int size = fields_.size();
  for (int i = 0; i < size; i++) {
    const TupleField &field = fields_[i];
    if (0 == strcmp(field.table_name(), table_name) && 0 == strcmp(field.field_name(), field_name)) {
      return i;
    }
  }
  return -1;
}

void TupleSchema::print(std::ostream &os) const {
  if (fields_.empty()) {
    os << "No schema";
    return;
  }

  // 判断有多张表还是只有一张表
  std::set<std::string> table_names;
  for (const auto &field: fields_) {
    table_names.insert(field.table_name());
  }

  for (std::vector<TupleField>::const_iterator iter = fields_.begin(), end = --fields_.end();
       iter != end; ++iter) {
    if (table_names.size() > 1) {
      os << iter->table_name() << ".";
    }
    os << iter->field_name() << " | ";
  }

  if (table_names.size() > 1) {
    os << fields_.back().table_name() << ".";
  }
  os << fields_.back().field_name() << std::endl;
}

void TupleSchema::print(std::ostream &os, std::vector<int> is_show) const {
  if (fields_.empty()) {
    os << "No schema";
    return;
  }

  // 判断有多张表还是只有一张表
  std::set<std::string> table_names;
  for (const auto &field: fields_) {
    table_names.insert(field.table_name());
  }
  int i = 0;
  int first = 0;
  int flag = 0;
  for (std::vector<TupleField>::const_iterator iter = fields_.begin(), end = --fields_.end();
       iter != end; ++iter) {
    if (is_show[i] == 1) {
      flag = 1;
      if (i > 0 && i != first){
        os << " | ";
      }
      if (table_names.size() > 1) {
        os << iter->table_name() << ".";
      }
      os << iter->field_name();
    }
    i++;
    if (flag==0){
      first++;
    }
  }
  if (is_show[i] == 1) {
    if (i != first) {
      os << " | ";
    }
    if (table_names.size() > 1) {
      os << fields_.back().table_name() << ".";
    }
    os << fields_.back().field_name();
  }
  os << std::endl;
}

/////////////////////////////////////////////////////////////////////////////
TupleSet::TupleSet(TupleSet &&other) : tuples_(std::move(other.tuples_)), schema_(other.schema_){
  other.schema_.clear();
}


TupleSet &TupleSet::operator=(TupleSet &&other) {
  if (this == &other) {
    return *this;
  }

  schema_.clear();
  schema_.append(other.schema_);
  other.schema_.clear();

  tuples_.clear();
  tuples_.swap(other.tuples_);
  return *this;
}

void TupleSet::add(Tuple &&tuple) {
  tuples_.emplace_back(std::move(tuple));
}

void TupleSet::clear() {
  tuples_.clear();
  schema_.clear();
}

void TupleSet::tuple_clear() {
  tuples_.clear();
}

void TupleSet::print(std::ostream &os) const {
  if (schema_.fields().empty()) {
    LOG_WARN("Got empty schema");
    return;
  }

  schema_.print(os);
  if (tuples_.front().size() == 0) return;
  for (const Tuple &item : tuples_) {
    const std::vector<std::shared_ptr<TupleValue>> &values = item.values();
    for (std::vector<std::shared_ptr<TupleValue>>::const_iterator iter = values.begin(), end = --values.end();
         iter != end; ++iter) {
      (*iter)->to_string(os);
      os << " | ";
    }
    values.back()->to_string(os);
    os << std::endl;
  }
}

void TupleSet::print(std::ostream &os, const Selects selects) const {
  if (schema_.fields().empty()) {
    LOG_WARN("Got empty schema");
    return;
  }
  std::vector<int> is_show;
  for (int i = 0; i < schema_.fields().size(); ++i) {
    if (schema_.field(i).isAgg()){
      is_show.push_back(1);
    } else {

    }
    is_show.push_back(0);
  }

  for (size_t i = 0; i < selects.relation_num; i++) {
    const char *table_name = selects.relations[i];
    for (int i = 0; i < selects.attr_num; i++) {
      const RelAttr &attr = selects.attributes[i];
      if (nullptr == attr.relation_name || 0 == strcmp(table_name, attr.relation_name)) {
        if ((0 == strcmp("*", attr.attribute_name) && attr.relation_name == nullptr) ||
            (0 == strcmp("*", attr.attribute_name) && attr.relation_name != nullptr && 0 == strcmp(table_name,attr.relation_name))) {
          for (int j = 0; j < schema_.fields().size(); ++j) {
            if (strcmp(schema_.field(j).table_name(),table_name)==0)
              is_show[j] = 1;
          }
        } else {
          for (int j = 0; j < schema_.fields().size(); ++j) {
            if (strcmp(schema_.field(j).table_name(),table_name)==0 && strcmp(schema_.field(j).field_name(),attr.attribute_name)==0)
              is_show[j] = 1;
          }
        }
      }
    }
  }
  schema_.print(os, is_show);

  for (const Tuple &item : tuples_) {
    const std::vector<std::shared_ptr<TupleValue>> &values = item.values();
    int i = 0;
    int first = 0;
    int flag = 0;
    for (std::vector<std::shared_ptr<TupleValue>>::const_iterator iter = values.begin(), end = --values.end();
          iter != end; ++iter) {
      if (is_show[i] == 1){
        if (i > 0 && i!=first) {
          os << " | ";
        }
        flag=1;
        (*iter)->to_string(os);
      }
      i++;
      if (flag == 0){
        first++;
      }
    }
    if (is_show[i] == 1) {
      if (i != first) {
        os << " | ";
      }
      values.back()->to_string(os);
    }
    os << std::endl;
  }
}

void TupleSet::set_schema(const TupleSchema &schema) {
  schema_ = schema;
}

void TupleSet::append_schema(const TupleSchema &schema) {
  schema_.append(schema);
}

const TupleSchema TupleSet::get_schema() const {
  return schema_;
}

bool TupleSet::is_empty() const {
  return tuples_.empty();
}

int TupleSet::size() const {
  return tuples_.size();
}

Tuple &TupleSet::get(int index) {
  return tuples_[index];
}

const std::vector<Tuple> &TupleSet::tuples() const {
  return tuples_;
}

void TupleSet::sort(OrderOp orderOps[],size_t orderOp_num) {
    std::sort(tuples_.begin(),tuples_.end(),[orderOps,orderOp_num, this](Tuple t1, Tuple t2){
        for (int i = 0; i < orderOp_num; ++i) {
            int index = schema_.index_of_field(orderOps[i].attr->relation_name,orderOps[i].attr->attribute_name);
            if(index==-1) continue;
            int r = t1.get(index).compare(t2.get(index));
            if (r==0){
                continue;
            }
            else{
                bool r1= r > 0? true: false ;
                bool r2 = !orderOps[i].direct;
                bool r3 = r1^r2;
                return r3;
            }
        }
        return false;
    });
}


////////////////////////////////////////////////////;/////////////////////////
//ConditionRecordConverter::ConditionRecordConverter(Table *table, std::vector<DefaultConditionFilter*> &condition_set,char *field_name) :
//        table_(table), condition_set_(condition_set), field_name_(field_name){
//}
//
//void ConditionRecordConverter::add_condition(const char *record) {
//  const TableMeta &table_meta = table_->table_meta();
//  const FieldMeta *field_meta = table_meta.field(field_name_);
//  DefaultConditionFilter *condition_filter = new DefaultConditionFilter();
//  switch (field_meta->type()) {
//    case INTS: {
//      int value = *(int*)(record + field_meta->offset());
//      Condition condition = {
//              1, nullptr,
//      };
//      RC rc = condition_filter->init();
//      condition_set_.
//    }
//      break;
//    case FLOATS: {
//      float value = *(float *)(record + field_meta->offset());
//      tuple.add(value);
//    }
//      break;
//    case CHARS: {
//      const char *s = record + field_meta->offset();  // 现在当做Cstring来处理
//      tuple.add(s, strlen(s));
//    }
//      break;
//    case DATES:{
//      int value = *(int*)(record + field_meta->offset());
//      int y = value/10000;
//      int m = (value-y*10000)/100;
//      int d = value-y*10000-m*100;
//      char s[20];
//      int n = sprintf(s, "%d-%02d-%02d", y, m, d);
//      tuple.add(s,strlen(s));
//    }
//      break;
//    default: {
//      LOG_PANIC("Unsupported field type. type=%d", field_meta->type());
//    }
//  }
//}

TupleRecordConverter::TupleRecordConverter(Table *table, TupleSet &tuple_set) :
      table_(table), tuple_set_(tuple_set){
}

void TupleRecordConverter::add_record(const char *record) {
  const TupleSchema &schema = tuple_set_.schema();
  Tuple tuple;
  const TableMeta &table_meta = table_->table_meta();
  const int null_bitmap = *(int *)(record+4);//TODO
  int i=0;
  for (const TupleField &field : schema.fields()) {
    const FieldMeta *field_meta = table_meta.field(field.field_name());
    assert(field_meta != nullptr);
    if(null_bitmap&1<<i){
        tuple.add("NULL",4);
        i++;
        continue;
    }
    i++;
    switch (field_meta->type()) {
      case INTS: {
        int value = *(int*)(record + field_meta->offset());
        tuple.add(value);
      }
      break;
      case FLOATS: {
        float value = *(float *)(record + field_meta->offset());
        tuple.add(value);
      }
        break;
      case CHARS: {
          if(!field_meta->is_text()){
              const char *s;
              s = record + field_meta->offset();
              tuple.add(s, strlen(s));
          }
          else{
              char *s = new char[4096]();
              int fd = table_->get_long_fd();
              long pos = *(long*)(record+field_meta->offset());
              lseek(fd,pos,SEEK_SET);
              read(fd,s,4096);
              if(strlen(s)>4096) tuple.add(s,4096);
              else tuple.add(s, strlen(s));
          }
      }
      break;
    case DATES:{
        int value = *(int*)(record + field_meta->offset());
        int y = value/10000;
        int m = (value-y*10000)/100;
        int d = value-y*10000-m*100;
        char s[20];
        int n = sprintf(s, "%d-%02d-%02d", y, m, d);
        tuple.add(s,strlen(s));
    }
            break;
      default: {
        LOG_PANIC("Unsupported field type. type=%d", field_meta->type());
      }
    }
  }

  tuple_set_.add(std::move(tuple));
}

TupleRecordAggregateConverter::TupleRecordAggregateConverter(Table *table, TupleSet &tuple_set, AggregateOp aggregateOp,const char *field_name) :
  table_(table), tuple_set_(tuple_set), aggregateOp_(aggregateOp),field_name_(field_name) {
  count = 0;
  agg_string = nullptr;
  if (aggregateOp == MIN_OP) {
    agg_int = 2147483647;
    agg_float = (float) 2147483647;
  } else {
    agg_int = 0;
    agg_float = 0;
  }
}

void TupleRecordAggregateConverter::aggregate_record(const char *record) {
  const TupleSchema &schema = tuple_set_.schema();
  int null_bitmap = *(int*)(record+4);
//  Tuple tuple;
  if (strcmp(field_name_,"*")==0 && aggregateOp_ == COUNT_OP){
    count += 1;
    return;
  }
  const TableMeta &table_meta = table_->table_meta();
  const FieldMeta *field_meta = table_meta.field(field_name_);
  if(null_bitmap&1<<field_meta->index_num()) return;
  assert(field_meta != nullptr);
  type = field_meta->type();
  count += 1;
  switch (aggregateOp_) {
    case MAX_OP: {
      switch (field_meta->type()) {
        case INTS: {
          int value = *(int*)(record + field_meta->offset());
          if (value > agg_int) {
            agg_int = value;
          }
        }
          break;
        case FLOATS: {
          float value = *(float *)(record + field_meta->offset());
          if (value > agg_float) {
            agg_float = value;
          }
        }
          break;
        case CHARS:{
          char *value = (char *)record + field_meta->offset();  // 现在当做Cstring来处理
          if (agg_string == nullptr || strcmp(value,agg_string)>0){
            agg_string = value;
          }
        }
          break;
        case DATES:{
          int value = *(int*)(record + field_meta->offset());
          if (value > agg_int) {
            agg_int = value;
          }
        }
          break;
        default: {
          return;
//          LOG_PANIC("Unsupported field type for this operation. type=%d", field_meta->type());
        }
      }
    }
      break;
    case MIN_OP: {
      switch (field_meta->type()) {
        case INTS: {
          int value = *(int*)(record + field_meta->offset());
          if (value < agg_int) {
            agg_int = value;
          }
        }
          break;
        case FLOATS: {
          float value = *(float *)(record + field_meta->offset());
          if (value < agg_float) {
            agg_float = value;
          }
        }
          break;
        case CHARS:{
          char *value = (char *)(record + field_meta->offset());
          if (agg_string == nullptr || strcmp(value,agg_string)<0){
            agg_string = value;
          }
        }
          break;
        case DATES:{
          int value = *(int*)(record + field_meta->offset());
          if (value < agg_int) {
            agg_int = value;
          }
        }
          break;
        default: {
          return;
//          LOG_PANIC("Unsupported field type for this operation. type=%d", field_meta->type());
        }
      }
    }
      break;
    case AVG_OP: {
      switch (field_meta->type()) {
        case INTS: {
          int value = *(int*)(record + field_meta->offset());
          agg_float += (float )value;
        }
          break;
        case FLOATS: {
          float value = *(float *)(record + field_meta->offset());
          agg_float += value;
        }
          break;
        default: {
          return;
//          LOG_PANIC("Unsupported field type for this operation. type=%d", field_meta->type());
        }
      }
    }
      break;
    default: {
      return;
//      LOG_PANIC("Unsupported field type for this operation. type=%d", field_meta->type());
    }
  }
//  tuple_set_.add(std::move(tuple));
}

TupleRecordAggregateGroupByConverter::TupleRecordAggregateGroupByConverter(Table *table, TupleSet &tuple_set,
             AggregateOp aggregateOp,const char *field_name,TupleSchema group_schema) :
  table_(table), tuple_set_(tuple_set), aggregateOp_(aggregateOp),field_name_(field_name), group_schema_(group_schema),count_(0) {
}

TupleRecordAggregateGroupByConverter::TupleRecordAggregateGroupByConverter(Table *table, TupleSet &tuple_set,
                                                                           TupleSchema group_schema) :
        table_(table), tuple_set_(tuple_set), aggregateOp_(NO_AG_OP),field_name_(nullptr), group_schema_(group_schema),count_(0) {
}

int float_compare2(float f1, float f2) {
  float result = f1 - f2;
  if (result < 1e-6 && result > -1e-6) {
    return 0;
  }
  return result > 0 ? 1 : -1;
}

int CompareKey2(const char *pdata, const char *pkey, AttrType attr_type, int attr_length) { // 简化
  int i1, i2;
  float f1, f2;
  const char *s1, *s2;
  switch (attr_type) {
    case DATES:
    case INTS: {
      i1 = *(int *) pdata;
      i2 = *(int *) pkey;
      if (i1 > i2)
        return 1;
      if (i1 < i2)
        return -1;
      if (i1 == i2)
        return 0;
    }
      break;
    case FLOATS: {
      f1 = *(float *) pdata;
      f2 = *(float *) pkey;
      return float_compare2(f1, f2);
    }
      break;
    case CHARS: {
      s1 = pdata;
      s2 = pkey;
      return strncmp(s1, s2, attr_length);
    }
      break;
    default: {
      LOG_PANIC("Unknown attr type: %d", attr_type);
    }
  }
  return -2;//This means error happens
}

int CompAttrs2(AttrType attr_type[], int attr_length[], int len, char *p1, char *p2){
  for(int i = 0; i < len; i++){
    int result = CompareKey2(p1, p2, attr_type[i], attr_length[i]);
    if(result != 0){
      return result;
    }
    p1 += attr_length[i];
    p2 += attr_length[i];
  }
  return 0;
}

int TupleRecordAggregateGroupByConverter::iterComp(std::unordered_map<char *, int>::iterator iter,AttrType attr_type[], char *p1, int attr_length[], int len){
  int flag = 0;
  for(iter=count_map.begin(); iter!=count_map.end(); iter++) {
    if (CompAttrs2(attr_type,attr_length,group_schema_.fields().size(),p1,iter->first) == 0) {
      flag = 1;
      break;
    }
  }
}

void TupleRecordAggregateGroupByConverter::group_record(const char *record){
  const TableMeta &table_meta = table_->table_meta();
  int total_length = 0;
  AttrType ts[group_schema_.fields().size()];
  int tns[group_schema_.fields().size()];
  for (int i = group_schema_.fields().size()-1; i >=0; --i) {
    const FieldMeta *field_meta = table_meta.field(group_schema_.field(i).field_name());
    total_length += field_meta->len();
    ts[i] = field_meta->type();
    tns[i] = field_meta->len();
  }
  char *key = (char *)malloc(total_length);
  int offset = 0;
  for (int i = group_schema_.fields().size()-1; i >=0; --i) {
    const FieldMeta *field_meta = table_meta.field(group_schema_.field(i).field_name());
    memcpy(key + offset, record + field_meta->offset(), field_meta->len());
    offset += field_meta->len();
  }
  std::unordered_map<char *, int>::iterator iter;
  int flag = 0;
  for(iter=count_map.begin(); iter!=count_map.end(); iter++) {
    if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,iter->first) == 0) {
      flag = 1;
      iter->second += 1;
    }
  }
  if (flag == 0) {
    count_map[key] = 1;
    count_ += 1;
    keys.push_back(key);
  }
}

void TupleRecordAggregateGroupByConverter::aggregate_group_record(const char *record) {

  const TableMeta &table_meta = table_->table_meta();
  const FieldMeta *agg_field_meta = table_meta.field(field_name_);
  type = agg_field_meta->type();

  int total_length = 0;
  AttrType ts[group_schema_.fields().size()];
  int tns[group_schema_.fields().size()];
  for (int i = group_schema_.fields().size()-1; i >=0; --i) {
    const FieldMeta *field_meta = table_meta.field(group_schema_.field(i).field_name());
    total_length += field_meta->len();
    ts[i] = field_meta->type();
    tns[i] = field_meta->len();
  }
  char *key = (char *)malloc(total_length);
  int offset = 0;
  for (int i = group_schema_.fields().size()-1; i >=0; --i) {
    const FieldMeta *field_meta = table_meta.field(group_schema_.field(i).field_name());
    memcpy(key + offset, record + field_meta->offset(), field_meta->len());
    offset += field_meta->len();
  }
//  std::string key_ = (std::string) key;

  std::unordered_map<char *, int>::iterator iter;
  int flag = 0;
  for(iter=count_map.begin(); iter!=count_map.end(); iter++) {
    if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,iter->first) == 0) {
      flag = 1;
      iter->second += 1;
    }
  }
  if (flag == 0) {
    count_map[key] = 1;
    count_ += 1;
    keys.push_back(key);
  }

  std::unordered_map<char *,int>::iterator int_iter;
  std::unordered_map<char *,float>::iterator float_iter;
  std::unordered_map<char *,std::string>::iterator string_iter;
//  if (count_map.find(key) != count_map.end()) {
//    count_map[key] += 1;
//  } else {
//    count_map[key] = 1;
//    count_ += 1;
//    keys.push_back(key);
//  }
  switch (aggregateOp_) {
    case MAX_OP: {
      switch (agg_field_meta->type()) {
        case INTS:
        case DATES: {
          int value = *(int*)(record + agg_field_meta->offset());
          int agg_int;
          int flag = 0;
          for(int_iter=agg_int_map.begin(); int_iter!=agg_int_map.end(); int_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter->first) == 0) {
              flag = 1;
              agg_int = int_iter->second;
              if (value > agg_int) {
                int_iter->second = value;
              }
            }
          }
          if (flag == 0) {
            agg_int_map[key] = value;
          }
        }
          break;
        case FLOATS: {
          float value = *(float *)(record + agg_field_meta->offset());
          float agg_float;
          int flag = 0;
          for(float_iter=agg_float_map.begin(); float_iter!=agg_float_map.end(); float_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,float_iter->first) == 0) {
              flag = 1;
              agg_float = float_iter->second;
              if (value > agg_float) {
                float_iter->second = value;
              }
              break;
            }
          }
          if (flag == 0) {
            agg_float_map[key] = value;
          }
        }
          break;
        case CHARS:{
          char *value = (char *)record + agg_field_meta->offset();
          std::string agg_string = agg_string_map[key];
          int flag = 0;
          for(string_iter=agg_string_map.begin(); string_iter!=agg_string_map.end(); string_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,string_iter->first) == 0) {
              flag = 1;
              agg_string = string_iter->second;
              if (strcmp(value,agg_string.c_str()) > 0) {
                string_iter->second = value;
              }
            }
          }
          if (flag == 0) {
            agg_string_map[key] = value;
          }
        }
          break;
        default: {
          return;
        }
      }
    }
      break;
    case MIN_OP: {
      switch (agg_field_meta->type()) {
        case INTS:
        case DATES: {
          int value = *(int*)(record + agg_field_meta->offset());
          int agg_int;
          int flag = 0;
          for(int_iter=agg_int_map.begin(); int_iter!=agg_int_map.end(); int_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter->first) == 0) {
              flag = 1;
              agg_int = int_iter->second;
              if (value < agg_int) {
                int_iter->second = value;
              }
            }
          }
          if (flag == 0) {
            agg_int_map[key] = value;
          }
        }
          break;
        case FLOATS: {
          float value = *(float *)(record + agg_field_meta->offset());
          float agg_float;
          for(float_iter=agg_float_map.begin(); float_iter!=agg_float_map.end(); float_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,float_iter->first) == 0) {
              flag = 1;
              agg_float = float_iter->second;
              if (value < agg_float) {
                float_iter->second = value;
              }
            }
          }
          if (flag == 0) {
            agg_float_map[key] = value;
          }
        }
          break;
        case CHARS:{
          char *value = (char *)record + agg_field_meta->offset();
          std::string agg_string = agg_string_map[key];
          int flag = 0;
          for(string_iter=agg_string_map.begin(); string_iter!=agg_string_map.end(); string_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,string_iter->first) == 0) {
              flag = 1;
              agg_string = string_iter->second;
              if (strcmp(value,agg_string.c_str()) < 0) {
                string_iter->second = value;
              }
            }
          }
          if (flag == 0) {
            agg_string_map[key] = value;
          }
        }
          break;
        default: {
          return;
        }
      }
    }
      break;
    case AVG_OP: {
      switch (agg_field_meta->type()) {
        case INTS: {
          int value = *(int*)(record + agg_field_meta->offset());
          float agg_float;
          int flag = 0;
          for(float_iter=agg_float_map.begin(); float_iter!=agg_float_map.end(); float_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,float_iter->first) == 0) {
              flag = 1;
              agg_float = float_iter->second;

              float_iter->second += (float)value;

            }
          }
          if (flag == 0) {
            agg_float_map[key] = (float)value;
          }
        }
          break;
        case FLOATS: {
          float value = *(float*)(record + agg_field_meta->offset());
          float agg_float;
          for(float_iter=agg_float_map.begin(); float_iter!=agg_float_map.end(); float_iter++) {
            if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,float_iter->first) == 0) {
              flag = 1;
              agg_float = float_iter->second;

              float_iter->second += value;

            }
          }
          if (flag == 0) {
            agg_float_map[key] = value;
          }
        }
          break;
        default: {
          return;
        }
      }
    }
      break;
    default: {
      return;
    }
  }
}
