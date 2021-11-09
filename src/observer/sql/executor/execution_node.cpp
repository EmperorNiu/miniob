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

void record_reader(const char *data, void *context) {
  TupleRecordConverter *converter = (TupleRecordConverter *)context;
  converter->add_record(data);
}


void record_aggregate(const char *data, void *context) {
  TupleRecordAggregateConverter *converter = (TupleRecordAggregateConverter *)context;
  converter->aggregate_record(data);
}


RC SelectExeNode::execute(TupleSet &tuple_set) {
  CompositeConditionFilter condition_filter;
  condition_filter.init((const ConditionFilter **)condition_filters_.data(), condition_filters_.size());

  tuple_set.clear();

  if (aggregateOps.size() == 0) {
    tuple_set.set_schema(tuple_schema_);
    TupleRecordConverter converter(table_, tuple_set);
    return table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_reader);
  } else {
    if (group_attrs.size() == 0) {
      tuple_set.set_schema(aggregate_schema_);
      TupleSchema schema;
      Tuple tuple = Tuple();
      for (int i = 0; i < aggregateOps.size(); ++i) {
        const char *field_name2 = aggregate_schema_.field(i).field_name();
        TupleRecordAggregateConverter converter(table_, tuple_set, aggregateOps[i], field_name2);
        RC rc = table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_aggregate);
        if (rc != RC::SUCCESS) {
          return rc;
        }
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
          schema.add(FLOATS,aggregate_schema_.field(i).table_name(),field_name.c_str());
        } else {
          schema.add(aggregate_schema_.field(i).type(),aggregate_schema_.field(i).table_name(),field_name.c_str());
        }
      }
      tuple_set.set_schema(schema);
      tuple_set.add(std::move(tuple));
      return RC::SUCCESS;
    }
    else {

    }
  }
}