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
// Created by Wangyunlai on 2021/5/7.
//

#include <stddef.h>
#include "condition_filter.h"
#include "record_manager.h"
#include "common/log/log.h"
#include "storage/common/table.h"

using namespace common;

ConditionFilter::~ConditionFilter()
{}

DefaultConditionFilter::DefaultConditionFilter()
{
  left_.is_attr = false;
  left_.attr_length = 0;
  left_.attr_offset = 0;
  left_.value = nullptr;

  right_.is_attr = false;
  right_.attr_length = 0;
  right_.attr_offset = 0;
  right_.value = nullptr;
}
DefaultConditionFilter::~DefaultConditionFilter()
{}

RC DefaultConditionFilter::init(const ConDesc &left, const ConDesc &right, AttrType attr_type, CompOp comp_op)
{
  if (attr_type < CHARS || attr_type > NULLS) {
    LOG_ERROR("Invalid condition with unsupported attribute type: %d", attr_type);
    return RC::INVALID_ARGUMENT;
  }

  if (comp_op < EQUAL_TO || comp_op >= NO_OP) {
    LOG_ERROR("Invalid condition with unsupported compare operation: %d", comp_op);
    return RC::INVALID_ARGUMENT;
  }

  left_ = left;
  right_ = right;
  attr_type_ = attr_type;
  comp_op_ = comp_op;
  return RC::SUCCESS;
}

RC DefaultConditionFilter::init(Table &table, const Condition &condition)
{
  const TableMeta &table_meta = table.table_meta();
  ConDesc left;
  ConDesc right;

  AttrType type_left = UNDEFINED;
  AttrType type_right = UNDEFINED;
  if (1 == condition.left_is_attr) {
    left.is_attr = true;
    const FieldMeta *field_left = table_meta.field(condition.left_attr.attribute_name);

    if (nullptr == field_left) {
      LOG_WARN("No such field in condition. %s.%s", table.name(), condition.left_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    left.index_num = field_left->index_num();
    left.attr_length = field_left->len();
    left.attr_offset = field_left->offset();

    left.value = nullptr;

    type_left = field_left->type();
  } else {
    left.is_attr = false;
    left.value = condition.left_value.data;  // 校验type 或者转换类型
    type_left = condition.left_value.type;

    left.attr_length = 0;
    left.attr_offset = 0;
  }

  if (1 == condition.right_is_attr) {
    right.is_attr = true;
    const FieldMeta *field_right = table_meta.field(condition.right_attr.attribute_name);
    if (nullptr == field_right) {
      LOG_WARN("No such field in condition. %s.%s", table.name(), condition.right_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    right.index_num = field_right->index_num();
    right.attr_length = field_right->len();
    right.attr_offset = field_right->offset();
    type_right = field_right->type();

    right.value = nullptr;
  } else {
    right.is_attr = false;

    right.value = condition.right_value.data;
    type_right = condition.right_value.type;

    right.attr_length = 0;
    right.attr_offset = 0;
  }
  int field_type_compare_compatible_table[6][6] = {
          1,0,0,0,0,1,
          0,1,0,0,0,1,
          0,0,1,1,0,1,
          0,0,1,1,0,1,
          0,0,0,0,1,1,
          1,1,1,1,1,1
  };
  // 校验和转换
  if (!field_type_compare_compatible_table[type_left][type_right]) {
    // 不能比较的两个字段， 要把信息传给客户端
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }else if(type_right==NULLS){
      if(type_left==type_right&&condition.comp>=6) return init(left,right,NULLS,CompOp (13-condition.comp));
      else return init(left,right,NULLS,condition.comp);
  }else if (!left.is_attr && right.is_attr) {
    return init(left, right, type_right, condition.comp);
  } else if (left.is_attr && !right.is_attr) {
    if (type_left==FLOATS && type_right==INTS) {
      tmp_f = (float)(*(int *) condition.right_value.data);
      right.value = &tmp_f;
    }
    else if (type_left==INTS && type_right==FLOATS) {
      tmp_i = (int)(*(float *) condition.right_value.data);
      right.value = &tmp_i;
    }
    return init(left, right, type_left, condition.comp);
  }
  // NOTE：这里没有实现不同类型的数据比较，比如整数跟浮点数之间的对比
  // 但是选手们还是要实现。这个功能在预选赛中会出现
//  if (left.is_attr == true && right.is_attr == false){
//    right.value
//  }
//  if (left.is_attr == false && right.is_attr == true) {}

//  if (type_left != type_right) {
//    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
//  }

  return init(left, right, type_left, condition.comp);
}

bool DefaultConditionFilter::filter(const Record &rec) const
{
  char *left_value = nullptr;
  char *right_value = nullptr;
  int null_bitmap = *(int *)(rec.data +4);
  int cmp_result = 0;
  if (left_.is_attr) {  // value
      if(null_bitmap&1<<left_.index_num&&comp_op_!=EQUAL_IS&&comp_op_!=EQUAL_IS_NOT) return false;
    left_value = (char *)(rec.data + left_.attr_offset);
  } else {
    left_value = (char *)left_.value;
  }

  if (right_.is_attr) {
      if(null_bitmap&1<<right_.index_num) return false;
    right_value = (char *)(rec.data + right_.attr_offset);
  } else {
    right_value = (char *)right_.value;
  }
  switch (attr_type_) {
    case CHARS: {  // 字符串都是定长的，直接比较
      // 按照C字符串风格来定
      cmp_result = strcmp(left_value, right_value);
    } break;
    case INTS: {
      // 没有考虑大小端问题
      // 对int和float，要考虑字节对齐问题,有些平台下直接转换可能会跪
      int left = *(int *)left_value;
      int right = *(int *)right_value;
      cmp_result = left - right;
    } break;
    case FLOATS: {
      float left = *(float *)left_value;
      float right = *(float *)right_value;
      if (left-right == 0)cmp_result =0;
      if (left-right > 0)cmp_result =1;
      if (left-right < 0)cmp_result =-1;
      // cmp_result = (int)(left - right);
    } break;
    case DATES:{
      int left = *(int *)left_value;
      int right = *(int *)right_value;
      cmp_result = left - right;
    } break;
    case NULLS: {
      bool isnull = null_bitmap & 1 << left_.index_num;
      return (isnull && comp_op_ == EQUAL_IS) || (!isnull && comp_op_ == EQUAL_IS_NOT);
    }
    default: {
    }
  }

  switch (comp_op_) {
    case EQUAL_IN:
    case EQUAL_TO:
      return 0 == cmp_result;
    case LESS_EQUAL:
      return cmp_result <= 0;
    case NOT_IN:
    case NOT_EQUAL:
      return cmp_result != 0;
    case LESS_THAN:
      return cmp_result < 0;
    case GREAT_EQUAL:
      return cmp_result >= 0;
    case GREAT_THAN:
      return cmp_result > 0;
    case EQUAL_IS:
        return false;
    case EQUAL_IS_NOT:
        return false;
    default:
      break;
  }

  LOG_PANIC("Never should print this.");
  return cmp_result;  // should not go here
}

CompositeConditionFilter::~CompositeConditionFilter()
{
  if (memory_owner_) {
    delete[] filters_;
    filters_ = nullptr;
  }
}

RC CompositeConditionFilter::init(const ConditionFilter *filters[], int filter_num, bool own_memory)
{
  filters_ = filters;
  filter_num_ = filter_num;
  memory_owner_ = own_memory;
  return RC::SUCCESS;
}
RC CompositeConditionFilter::init(const ConditionFilter *filters[], int filter_num)
{
  return init(filters, filter_num, false);
}

RC CompositeConditionFilter::init(Table &table, const Condition *conditions, int condition_num)
{
  if (condition_num == 0) {
    return RC::SUCCESS;
  }
  if (conditions == nullptr) {
    return RC::INVALID_ARGUMENT;
  }

  RC rc = RC::SUCCESS;
  ConditionFilter **condition_filters = new ConditionFilter *[condition_num];
  for (int i = 0; i < condition_num; i++) {
    DefaultConditionFilter *default_condition_filter = new DefaultConditionFilter();
    rc = default_condition_filter->init(table, conditions[i]);
    if (rc != RC::SUCCESS) {
      delete default_condition_filter;
      for (int j = i - 1; j >= 0; j--) {
        delete condition_filters[j];
        condition_filters[j] = nullptr;
      }
      delete[] condition_filters;
      condition_filters = nullptr;
      return rc;
    }
    condition_filters[i] = default_condition_filter;
  }
  return init((const ConditionFilter **)condition_filters, condition_num, true);
}

bool CompositeConditionFilter::filter(const Record &rec) const
{
  std::vector<const ConditionFilter*> orC;
  for (int i = 0; i < filter_num_; i++) {
    if(filters_[i]->isIn()) {
      orC.push_back(filters_[i]);
    }
  }
  int flag = 0;
  for (auto & i : orC) {
    if (i->filter(rec)) {
      flag = 1;
    }
  }
  if (flag == 0 && orC.size() > 0) return false;

  for (int i = 0; i < filter_num_; i++) {
    if (!filters_[i]->filter(rec) && !filters_[i]->isIn()) {
      return false;
    }
  }
  return true;
}


bool DefaultConditionFilter::isIn() const {
  return comp_op_ == EQUAL_IN;
}

bool DefaultConditionFilter::isNotIn() const {
  return comp_op_ == NOT_EQUAL;
}

bool CompositeConditionFilter::isIn() const {
  return false;
}

bool CompositeConditionFilter::isNotIn() const {
  return false;
}