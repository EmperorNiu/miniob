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

#include "sql/executor/execution_node.h"
#include "storage/common/table.h"
#include "common/log/log.h"
#include "tuple.h"

SelectExeNode::SelectExeNode() : table_(nullptr) {
}

SelectExeNode::~SelectExeNode() {
  for (DefaultConditionFilter * &filter : condition_filters_) {
    delete filter;
  }
  condition_filters_.clear();
}

RC SelectExeNode::init(Trx *trx, Table *table, TupleSchema &&tuple_schema, std::vector<DefaultConditionFilter *> &&condition_filters) {
  trx_ = trx;
  table_ = table;
  tuple_schema_ = tuple_schema;
  condition_filters_ = std::move(condition_filters);
  return RC::SUCCESS;
}

RC SelectExeNode::set_aggregate_schema(TupleSchema && tuple_schema){
  aggregate_schema_ = tuple_schema;
  return RC::SUCCESS;
}

RC SelectExeNode::set_group_schema(TupleSchema && tuple_schema){
  group_schema_ = tuple_schema;
  return RC::SUCCESS;
}


void record_reader(const char *data, void *context) {
  TupleRecordConverter *converter = (TupleRecordConverter *)context;
  converter->add_record(data);
}


void record_aggregate(const char *data, void *context) {
  TupleRecordAggregateConverter *converter = (TupleRecordAggregateConverter *)context;
  converter->aggregate_record(data);
}

void record_group_aggregate(const char *data, void *context) {
  TupleRecordAggregateGroupByConverter *converter = (TupleRecordAggregateGroupByConverter *)context;
  converter->aggregate_group_record(data);
}

void record_group(const char *data, void *context) {
  TupleRecordAggregateGroupByConverter *converter = (TupleRecordAggregateGroupByConverter *)context;
  converter->group_record(data);
}

RC SelectExeNode::execute(TupleSet &tuple_set) {
  CompositeConditionFilter condition_filter;
  condition_filter.init((const ConditionFilter **)condition_filters_.data(), condition_filters_.size());
  tuple_set.clear();
  int aggregateOp_num = aggregateOps.size();
  if (aggregateOp_num == 0) {
    tuple_set.set_schema(tuple_schema_);
    TupleRecordConverter converter(table_, tuple_set);
    return table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_reader);
  } else {
    // tuple_set.set_schema(aggregate_schema_);
    TupleSchema schema;

    if (group_schema_.fields().size() > 0){
      TupleSet group_tupleSet;
      const TableMeta &table_meta = table_->table_meta();
      // 添加 group 列
      for (int i = group_schema_.fields().size()-1; i >=0; --i) {
        schema.add(group_schema_.field(i).type(),
                   group_schema_.field(i).table_name(),group_schema_.field(i).field_name());
      }
      TupleRecordAggregateGroupByConverter group_converter(table_,tuple_set,group_schema_);
      RC rc = table_->scan_record(trx_, &condition_filter, -1, (void *)&group_converter, record_group);
      if (rc != RC::SUCCESS) return rc;
      for (int j = 0; j < group_converter.count(); ++j) {
        Tuple tuple = Tuple();
        int offset = 0;
        for (int k = group_schema_.fields().size()-1; k >=0; --k) {
          const FieldMeta *field_meta = table_meta.field(group_schema_.field(k).field_name());

          switch (field_meta->type()) {
            case INTS: {
              int value = *(int *)(group_converter.keys[j] + offset);
              tuple.add(value);
              break;
            }
            case FLOATS: {
              float value = *(float *)(group_converter.keys[j] + offset);
              tuple.add(value);
              break;
            }
            case DATES: {
              int value = *(int *)(group_converter.keys[j] + offset);
              int y = value/10000;
              int m = (value-y*10000)/100;
              int d = value-y*10000-m*100;
              char s[20];
              int n = sprintf(s, "%d-%02d-%02d", y, m, d);
              tuple.add(s,strlen(s));
              break;
            }
            case CHARS: {
              char *value = (char *)(group_converter.keys[j] + offset);
              tuple.add(value, strlen(value));
              break;
            }
          }
          offset += field_meta->len();
        }
        group_tupleSet.add(std::move(tuple));
      }

      // 添加 agg 列
      for (int i = 0; i <aggregateOp_num; ++i) {
        TupleSet tupleSet_;
        const char *aggregation_field = aggregate_schema_.field(i).field_name();
        TupleRecordAggregateGroupByConverter converter(table_,
                               tuple_set, aggregateOps[i], aggregation_field,group_schema_);
        RC rc = table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_group_aggregate);
        if (rc != RC::SUCCESS) return rc;
        std::unordered_map<char * ,int>::iterator int_iter2;
        std::unordered_map<char *,int>::iterator int_iter1;
        std::unordered_map<char *,float>::iterator float_iter;
        std::unordered_map<char *,std::string>::iterator string_iter;
        std::string field_name;
        for (int j = 0; j < converter.count(); ++j) {

          Tuple tuple = group_tupleSet.tuples()[j];
          int total_length=0;
          int offset = 0;
          AttrType ts[group_schema_.fields().size()];
          int tns[group_schema_.fields().size()];
          for (int ii = group_schema_.fields().size() - 1; ii >= 0; --ii) {
            const FieldMeta *field_meta = table_meta.field(group_schema_.field(ii).field_name());
            total_length += field_meta->len();
            ts[ii] = field_meta->type();
            tns[ii] = field_meta->len();
          }
//          char key[total_length];
          char *key = (char *)malloc(total_length);
          for (int ii = group_schema_.fields().size() - 1; ii >= 0; --ii) {
            const FieldMeta *field_meta = table_meta.field(group_schema_.field(ii).field_name());
            memcpy(key + offset, converter.keys[j] + offset, field_meta->len());
            offset += field_meta->len();
          }
          switch (aggregateOps[i]) {
            case MAX_OP:
              field_name = "MAX(" + (std::string)aggregation_field + ")";
              if (converter.type == INTS) {
                for(int_iter1=converter.agg_int_map.begin(); int_iter1!=converter.agg_int_map.end(); int_iter1++){
                  if(memcmp(key,int_iter1->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter1->first) == 0){
                    tuple.add(int_iter1->second);
                    break;
                  }
                }
              }
              if (converter.type == FLOATS) {
                for(float_iter=converter.agg_float_map.begin(); float_iter!=converter.agg_float_map.end(); float_iter++){
                  if(memcmp(key,float_iter->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,float_iter->first) == 0){
                    tuple.add(float_iter->second);
                    break;
                  }
                }
              }
              if (converter.type == CHARS) {
                for(string_iter=converter.agg_string_map.begin(); string_iter!=converter.agg_string_map.end(); string_iter++){
                  if(memcmp(key,string_iter->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,string_iter->first) == 0){
                    tuple.add(string_iter->second.c_str(), strlen(string_iter->second.c_str()));
                    break;
                  }
                }
              }
              if (converter.type == DATES) {
                for(int_iter1=converter.agg_int_map.begin(); int_iter1!=converter.agg_int_map.end(); int_iter1++){
                  if(memcmp(key,int_iter1->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter1->first) == 0){
                    int value = int_iter1->second;
                    int y = value/10000;
                    int m = (value-y*10000)/100;
                    int d = value-y*10000-m*100;
                    char s[20];
                    int n = sprintf(s, "%d-%02d-%02d", y, m, d);
                    tuple.add(s, strlen(s));
                    break;
                  }
                }
              }
              break;
            case MIN_OP:
              field_name = "MIN(" + (std::string)aggregation_field + ")";
              if (converter.type == INTS) {
                for(int_iter1=converter.agg_int_map.begin(); int_iter1!=converter.agg_int_map.end(); int_iter1++){
                  if(memcmp(key,int_iter1->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter1->first) == 0){
                    tuple.add(int_iter1->second);
                  }
                }
              }
              if (converter.type == FLOATS) {
                for(float_iter=converter.agg_float_map.begin(); float_iter!=converter.agg_float_map.end(); float_iter++){
                  if(memcmp(key,float_iter->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,float_iter->first) == 0){
                    tuple.add(float_iter->second);
                  }
                }
              }
              if (converter.type == CHARS) {
                for(string_iter=converter.agg_string_map.begin(); string_iter!=converter.agg_string_map.end(); string_iter++){
                  if(memcmp(key,string_iter->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,string_iter->first) == 0){
                    tuple.add(string_iter->second.c_str(), strlen(string_iter->second.c_str()));
                    break;
                  }
                }
              }
              if (converter.type == DATES) {
                for(int_iter1=converter.agg_int_map.begin(); int_iter1!=converter.agg_int_map.end(); int_iter1++){
                  if(memcmp(key,int_iter1->first,total_length) == 0){
//                  if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter1->first) == 0){
                    int value = int_iter1->second;
                    int y = value/10000;
                    int m = (value-y*10000)/100;
                    int d = value-y*10000-m*100;
                    char s[20];
                    int n = sprintf(s, "%d-%02d-%02d", y, m, d);
                    tuple.add(s, strlen(s));
                  }
                }
              }
              break;
            case COUNT_OP:
              field_name = "COUNT(" + (std::string)aggregation_field + ")";
              for(int_iter2=converter.count_map.begin(); int_iter2!=converter.count_map.end(); int_iter2++){
                if(memcmp(key,int_iter2->first,total_length) == 0){
//                if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter2->first) == 0){
                  tuple.add(int_iter2->second);
                  break;
                }
              }
              break;
            case AVG_OP:
              if (converter.type == INTS || converter.type == FLOATS){
                field_name = "AVG(" + (std::string)aggregation_field + ")";
                for(float_iter=converter.agg_float_map.begin(); float_iter!=converter.agg_float_map.end(); float_iter++){
                  for(int_iter2=converter.count_map.begin(); int_iter2!=converter.count_map.end(); int_iter2++){
                    if(memcmp(key,float_iter->first,total_length) == 0 && memcmp(key,int_iter2->first,total_length)){
//                    if (CompAttrs2(ts,tns,group_schema_.fields().size(),key,float_iter->first) == 0
//                        && CompAttrs2(ts,tns,group_schema_.fields().size(),key,int_iter2->first) == 0){
                      tuple.add(float_iter->second/int_iter2->second);
                      break;
                    }
                  }
                }
              }
              break;
            default:
              return RC::INVALID_ARGUMENT;
          }
          tupleSet_.add(std::move(tuple));
//          if(int_iter1!=converter.agg_int_map.end()) int_iter1++;
//          if(int_iter2!=converter.count_map.end()) int_iter2++;
//          if(float_iter!=converter.agg_float_map.end()) float_iter++;
//          if(string_iter!=converter.agg_string_map.end()) string_iter++;

        }
        if (aggregateOps[i] == AVG_OP){
          schema.add(FLOATS,aggregate_schema_.field(i).table_name(),field_name.c_str(),1);
        } else {
          schema.add(aggregate_schema_.field(i).type(),aggregate_schema_.field(i).table_name(),field_name.c_str(),1);
        }
        group_tupleSet = TupleSet(std::move(tupleSet_));
        tupleSet_.tuple_clear();
      }
      tuple_set = TupleSet(std::move(group_tupleSet));
      tuple_set.set_schema(schema);
      return RC::SUCCESS;
    }
    Tuple tuple = Tuple();
    for (int i = 0; i < aggregateOp_num; ++i) {
      const char *field_name2 = aggregate_schema_.field(i).field_name();
      TupleRecordAggregateConverter converter(table_, tuple_set, aggregateOps[i], field_name2);
      RC rc = table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_aggregate);
      if (rc != RC::SUCCESS) return rc;

      std::string field_name;
      switch (aggregateOps[i]) {
        case MAX_OP:
          field_name = "MAX(" + (std::string)field_name2 + ")";
          if (converter.type == INTS) tuple.add(converter.agg_int);
          if (converter.type == FLOATS) tuple.add(converter.agg_float);
          if (converter.type == CHARS) tuple.add(converter.agg_string, strlen(converter.agg_string));
          if (converter.type == DATES) {
            int value = converter.agg_int;
            int y = value/10000;
            int m = (value-y*10000)/100;
            int d = value-y*10000-m*100;
            char s[20];
            int n = sprintf(s, "%d-%02d-%02d", y, m, d);
            tuple.add(s,strlen(s));
          }
          break;
        case MIN_OP:
          field_name = "MIN(" + (std::string)field_name2 + ")";
          if (converter.type == INTS) tuple.add(converter.agg_int);
          if (converter.type == FLOATS) tuple.add(converter.agg_float);
          if (converter.type == CHARS) tuple.add(converter.agg_string, strlen(converter.agg_string));
          if (converter.type == DATES) {
            int value = converter.agg_int;
            int y = value/10000;
            int m = (value-y*10000)/100;
            int d = value-y*10000-m*100;
            char s[20];
            int n = sprintf(s, "%d-%02d-%02d", y, m, d);
            tuple.add(s,strlen(s));
          }
          break;
        case COUNT_OP:
          field_name = "COUNT(" + (std::string)field_name2 + ")";
          tuple.add(converter.count);
          break;
        case AVG_OP:
          if (converter.type == INTS || converter.type == FLOATS){
            field_name = "AVG(" + (std::string)field_name2 + ")";
            tuple.add(converter.agg_float/converter.count);
          }
          break;
        default:
          return RC::INVALID_ARGUMENT;
      }
      if (aggregateOps[i] == AVG_OP){
        schema.add(FLOATS,aggregate_schema_.field(i).table_name(),field_name.c_str(),1);
      } else {
        schema.add(aggregate_schema_.field(i).type(),aggregate_schema_.field(i).table_name(),field_name.c_str(),1);
      }
    }
    tuple_set.set_schema(schema);
    tuple_set.add(std::move(tuple));
    return RC::SUCCESS;
  }
}