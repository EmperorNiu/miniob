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

#ifndef __OBSERVER_SQL_EXECUTOR_TUPLE_H_
#define __OBSERVER_SQL_EXECUTOR_TUPLE_H_

#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <storage/common/condition_filter.h>
#include <storage/common/table_meta.h>

#include "sql/parser/parse.h"
#include "sql/executor/value.h"

class Table;

class Tuple {
public:
  Tuple() = default;

  Tuple(const Tuple &other);

  ~Tuple();

  Tuple(Tuple &&other) noexcept ;
  Tuple & operator=(Tuple &&other) noexcept ;

  void add(TupleValue *value);
  void add(const std::shared_ptr<TupleValue> &other);
  void add(int value);
  void add(float value);
  void add(const char *s, int len);

  const std::vector<std::shared_ptr<TupleValue>> &values() const {
    return values_;
  }

  int size() const {
    return values_.size();
  }

  TupleValue &get(int index) {
    return *values_[index];
  }

  const std::shared_ptr<TupleValue> &get_pointer(int index) const {
    return values_[index];
  }

private:
  std::vector<std::shared_ptr<TupleValue>>  values_;
};

class TupleField {
public:
  TupleField(AttrType type, const char *table_name, const char *field_name) :
          type_(type), table_name_(table_name), field_name_(field_name), is_agg_field_(0){
  }
  TupleField(AttrType type, const char *table_name, const char *field_name, int isAgg) :
          type_(type), table_name_(table_name), field_name_(field_name), is_agg_field_(isAgg){
  }

  AttrType  type() const{
    return type_;
  }

  int isAgg() const{
    return is_agg_field_;
  }

  const char *table_name() const {
    return table_name_.c_str();
  }
  const char *field_name() const {
    return field_name_.c_str();
  }

  std::string to_string() const;
private:
  AttrType  type_;
  std::string table_name_;
  std::string field_name_;
  int is_agg_field_;
};

class TupleSchema {
public:
  TupleSchema() = default;
  ~TupleSchema() = default;

  void add(AttrType type, const char *table_name, const char *field_name);
  void add(AttrType type, const char *table_name, const char *field_name, int isAgg);
  void add_if_not_exists(AttrType type, const char *table_name, const char *field_name);
  // void merge(const TupleSchema &other);
  void append(const TupleSchema &other);

  const std::vector<TupleField> &fields() const {
    return fields_;
  }

  const TupleField &field(int index) const {
    return fields_[index];
  }

  int index_of_field(const char *table_name, const char *field_name) const;
  void clear() {
    fields_.clear();
  }

  void print(std::ostream &os) const;
  void print(std::ostream &os, std::vector<int> is_show) const;
public:
  static void from_table(const Table *table, TupleSchema &schema);
private:
  std::vector<TupleField> fields_;
};

class TupleSet {
public:
  TupleSet() = default;
  TupleSet(TupleSet &&other);
  explicit TupleSet(const TupleSchema &schema) : schema_(schema) {
  }
  TupleSet &operator =(TupleSet &&other);

  ~TupleSet() = default;

  void set_schema(const TupleSchema &schema);
  void append_schema(const TupleSchema &schema);
  void sort(OrderOp orderOps[],size_t orderOp_num);
  const TupleSchema get_schema() const;

  void add(Tuple && tuple);

  void clear();
  void tuple_clear();

  bool is_empty() const;
  int size() const;
  Tuple &get(int index);
  const std::vector<Tuple> &tuples() const;

  void print(std::ostream &os) const;
  void print(std::ostream &os, const Selects selects) const;
public:
  const TupleSchema &schema() const {
    return schema_;
  }
private:
  std::vector<Tuple> tuples_;
  TupleSchema schema_;


};

//class ConditionRecordConverter {
//public:
//    ConditionRecordConverter(Table *table, std::vector<DefaultConditionFilter*> &condition_set,char *field_name);
//
//    void add_condition(const char *record);
//private:
//    Table *table_;
//    std::vector<DefaultConditionFilter*> &condition_set_;
//    char *field_name_;
//};


class TupleRecordConverter {
public:
  TupleRecordConverter(Table *table, TupleSet &tuple_set);

  void add_record(const char *record);
private:
  Table *table_;
  TupleSet &tuple_set_;
};

class TupleRecordAggregateConverter {
public:
    TupleRecordAggregateConverter(Table *table, TupleSet &tuple_set, AggregateOp aggregateOp,const char *field_name);
    void aggregate_record(const char *record);
    int count;
    int agg_int;
    float agg_float;
    char *agg_string;
    AttrType type;
private:
    Table *table_;
    TupleSet &tuple_set_;
    AggregateOp aggregateOp_;
    const char *field_name_;
};

class TupleRecordAggregateGroupByConverter {
public:
    TupleRecordAggregateGroupByConverter(Table *table, TupleSet &tuple_set,AggregateOp aggregateOp,
                            const char *field_name,TupleSchema group_schema);
    TupleRecordAggregateGroupByConverter(Table *table, TupleSet &tuple_set,TupleSchema group_schema);
    void aggregate_group_record(const char *record);
    int cmpKey(std::string s1,std::string s2);
    struct cmp_str
    {
        bool operator()(char const *a, char const *b) const
        {
          return strcmp(a, b) < 0;
        }
    };
    void group_record(const char *record);
    std::map<char *,int> count_map;
    std::map<char *,int> agg_int_map;
    std::map<char *,float> agg_float_map;
    std::map<char *,std::string> agg_string_map;
    std::vector<char *> keys;
    int iterComp(std::map<char *, int>::iterator iter,AttrType attr_type[], char *p1, int attr_length[], int len);
    int count() { return count_; }
    AttrType type;
private:

    Table *table_;
    int count_;
    TupleSet &tuple_set_;
    AggregateOp aggregateOp_; // aggregate operator
    const char *field_name_;  // aggregated field name
    TupleSchema group_schema_;
};

#endif //__OBSERVER_SQL_EXECUTOR_TUPLE_H_
