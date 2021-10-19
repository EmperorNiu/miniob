## Introduction
miniob设计的目标是让不熟悉数据库设计和实现的同学能够快速的了解与深入学习数据库内核，期望通过miniob相关训练之后，能够对各个数据库内核模块的功能与它们之间的关联有所了解，并能够在
使用时，设计出高效的SQL。面向的对象主要是在校学生，并且诸多模块做了简化，比如不考虑并发操作。
注意：此代码仅供学习使用，不考虑任何安全特性。

# How to build
please refer to docs/how_to_build.md


# 如何启动

## 启动 obclient

```shell
./bin/obclient
```

## 启动 obserber

```shell
./bin/observer -f ../etc/observer.ini 
```

启动后会在build目录下产生日志文件

## miniob基本架构

### 网络模块

负责与客户端交互，收发客户端请求与应答，在 src/observer/net 目录下

## SQL解析

将用户输入的SQL语句解析成语法树，在 observer/sql/parser 目录下

词法解析、语法解析

## 计划执行

根据语法树描述执行并生成结果, 在 observer/sql/executor 目录下，根据用户输入命令执行对应的语句

## 会话管理

observer/session

## 元数据管理

表、字段和索引的元数据

observer/storage/common

## 客户端

测试工具，接受用户请求向服务端发起请求
obclient
 

## 执行计划缓存

observer/sql/plan_cache

将SQL第一次生成的执行计划缓存在内存中，后续的额执行可以反复执行这个计划

## 语言解析

将生成的语法树转换成数据库内部数据结构

sql/parser


## 查询缓存

将执行的查询结果缓存在内存中，下次查询时可以直接从query_cache中返回

## 查询优化

根据统计信息，调整重写语法树。着重

observer/sql


## seda 可跳过

SEDA 事件处理框架；结合事件驱动和多线程模式两者的优点，从而做到易扩展解耦合高并发

deps/common/seda

使用方法参看session 下面的session_stage