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

RC
SelectExeNode::init(Trx *trx, Table *table, TupleSchema &&tuple_schema, std::vector<DefaultConditionFilter *> &&condition_filters) {
  trx_ = trx;
  table_ = table;
  tuple_schema_ = tuple_schema;
  condition_filters_ = std::move(condition_filters);
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
  tuple_set.set_schema(tuple_schema_);

  if (aggregateOp == NO_AG_OP) {
    TupleRecordConverter converter(table_, tuple_set);
    return table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_reader);
  } else {
    TupleRecordAggregateConverter converter(table_, tuple_set, aggregateOp);
    RC rc = table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_aggregate);

    TupleSchema schema;
    std::string field_name;
    Tuple tuple = Tuple();
    switch (aggregateOp) {
      case MAX_OP:
        field_name = "MAX("+(std::string)tuple_schema_.field(0).field_name()+")";
        if (converter.type == INTS) tuple.add(converter.agg_int);
        if (converter.type == FLOATS) tuple.add(converter.agg_float);
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
        field_name = "MIN("+(std::string)tuple_schema_.field(0).field_name()+")";
        if (converter.type == INTS) tuple.add(converter.agg_int);
        if (converter.type == FLOATS) tuple.add(converter.agg_float);
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
        field_name = "COUNT("+(std::string)tuple_schema_.field(0).field_name()+")";
        tuple.add(converter.count);
        break;
      case AVG_OP:
        field_name = "AVG("+(std::string)tuple_schema_.field(0).field_name()+")";
        if (converter.type == INTS) tuple.add(converter.agg_int/converter.count);
        if (converter.type == FLOATS) tuple.add(converter.agg_float/converter.count);
        break;
      default:
        return RC::INVALID_ARGUMENT;
    }
    schema.add(tuple_schema_.field(0).type(),tuple_schema_.field(0).table_name(),field_name.c_str());
    tuple_set.set_schema(schema);
    tuple_set.add(std::move(tuple));
    return rc;
  }

}