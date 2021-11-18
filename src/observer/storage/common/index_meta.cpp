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
// Created by wangyunlai.wyl on 2021/5/18.
//

#include "storage/common/index_meta.h"
#include "storage/common/field_meta.h"
#include "storage/common/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "rc.h"
#include "json/json.h"

const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString FIELD_FIELD_NAME("field_name");
const static Json::StaticString IS_UNIQUE("isUnique");

RC IndexMeta::init(const char *name, const FieldMeta &field) {
  if (nullptr == name || common::is_blank(name)) {
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  field_ = field.name();
  return RC::SUCCESS;
}

RC IndexMeta::init(const char *name, const FieldMeta &field, const int isUnique) {
  if (nullptr == name || common::is_blank(name)) {
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  field_ = field.name();
  isUnique_ = isUnique;
  return RC::SUCCESS;
}

RC IndexMeta::init(const char *name, std::vector<const FieldMeta*> &fields, const int isUnique) {
  if (nullptr == name || common::is_blank(name)) {
    return RC::INVALID_ARGUMENT;
  }
  name_ = name;
  for(const auto & field : fields){
    fields_.emplace_back(field->name());
  }
  isUnique_ = isUnique;
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const {
  json_value[FIELD_NAME] = name_;
  std::string fields = "";
  for (int i = 0; i < fields_.size(); ++i) {
    fields += fields_[i];
    fields += ' ';
  }
  json_value[FIELD_FIELD_NAME] = fields;
  json_value[IS_UNIQUE] = isUnique_;
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index) {
  const Json::Value &name_value = json_value[FIELD_NAME];
  const Json::Value &field_value = json_value[FIELD_FIELD_NAME];
  const Json::Value &unique_value = json_value[IS_UNIQUE];
  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  if (!field_value.isString()) {
    LOG_ERROR("Field name of index [%s] is not a string. json value=%s",
              name_value.asCString(), field_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }
  std::vector<std::string> fields;
  std::string s = field_value.asCString();
  size_t pos = 0;
  std::string token;
  std::string delimiter = " ";
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    fields.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  std::vector<const FieldMeta *> field_metas;
  for (int i = 0; i < fields.size(); ++i) {
    const FieldMeta *field = table.field(fields[i].c_str());
    if (nullptr == field) {
      LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), field_value.asCString());
      return RC::SCHEMA_FIELD_MISSING;
    }
    field_metas.push_back(field);
  }
  return index.init(name_value.asCString(), field_metas, unique_value.asInt());
}

const char *IndexMeta::name() const {
  return name_.c_str();
}

const char *IndexMeta::field() const {
  return field_.c_str();
}

const char *IndexMeta::field(int i) const {
  return fields_[i].c_str();
}

std::vector<std::string> IndexMeta::get_fields() const{
  return fields_;
}

const int IndexMeta::isUnique() const{
    return isUnique_;
}

void IndexMeta::desc(std::ostream &os) const {
  os << "index name=" << name_
      << ", field=" << field_;
}