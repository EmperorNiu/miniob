
## basic (通过)

## 优化buffer pool


## 查询元数据校验 (通过)

查询语句中存在不存在的列名、表名等，需要返回失败。需要检查代码，判断是否需要返回错误的地方都返回错误了。

1. 校验表名是否存在
2. 校验where中的字段
3. 校验投影字段（select后的字段）

## drop table (通过)

删除表。清除表相关的资源。

1. 删除不存在的表时返回 FAILURE
2. 删除表的table文件、data文件
3. 删除 index 文件
4. 更新opened_table, 并清理内存


## 实现update功能

update单个字段

1. 符合规范的更新
2. 与表的meta data 不符的更新返回 FAILURE
3. 其他错误校验

TODO
trx 版本是否需要完成

问题在哪 ？ 待解决

## 增加date字段

date测试不会超过2038年2月。注意处理非法的date输入，需要返回FAILURE。

1. 创建表时声明date字段
2. 使用date字段进行比较查询
3. 不合法日期校验，包括插入，更新和作为条件

问题在哪 ？ 待解决

## 多表查询


1. 使用嵌套循环连接

## 聚合运算

实现max/min/count/avg. 包含聚合字段时，只会出现聚合字段。聚合函数中的参数不会是表达式，比如age +1


## 问题

select 对float类型筛选时存在问题 差值小于1 （condition filter）