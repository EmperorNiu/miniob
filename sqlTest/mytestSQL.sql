create table t(id int, age int);
drop table t;
create table t(id int, name int);
insert into t values(2, 22);
insert into t values(4, 53);
select * from t;
update t set name = 200 where id>1;
select * from t;
-- date
select * from t1 where birthday > "2000-03-15";

/* select tables*/
create table j1(id int, height float, name char, birthday date);
create table j2(id int, height float, name char, birthday date);
create table j3(id int, height float, name char, birthday date);
insert into j1 values(1, 2.4, 't1', '1999-01-13');
insert into j1 values(2, 2.2, 't2', '1939-01-13');
insert into j1 values(3, 2.5, 't5', '1939-04-16');
insert into j2 values(2, 2.4, 't3', '1949-01-13');
insert into j2 values(3, 2.7, 't5', '1969-04-16');
insert into j2 values(4, 5.3, 't4', '1959-01-13');
insert into j3 values(5, 5.3, 't2', '1959-01-13');
insert into j3 values(4, 3.1, 't3', '1999-01-13');
select * from j1,j2;
select * from j1,j2 order by j1.id desc,j2.height;
select * from j1,j2,j3;
select * from j1,j2 where j1.id=j2.id;
select * from j1,j2 where j1.id=j2.id;
select * from j1,j2 where j2.id=j1.id;
select j1.height,j2.height from j1,j2 where j1.id=j2.id;
select j1.* , j2.* from j1,j2 where j1.id=j2.id;
select j1.*, j2.* from j1,j2;
select j1.*, j2.height from j1,j2;
select j1.id from j1,j2;

select j1.height from j1 where j1.height<2.4;
select j1.height from j1,j2 where j1.height<=2.4 and j1.height=j2.height;
select * from j1,j2,j3 where j1.id=j2.id and j3.height=5.3;
select * from j1,j2,j3 where j1.id=j2.id;

select * from j1,j2 where j2.id>j1.id;
select * from j1,j2 where j1.id<j2.id;

select id from j1;
select j4.age,j2.age from j1,j2 where j1.id=j2.id;
select j1.agdsfe,j2.age from j1,j2 where j1.id=j2.id;


create table t3(id int, age date);
insert into t3 values(3, "2021-2-28");
update t3 set age="2021-3-28" where id=1;
update t3 set id=20 where age="2021-02-28";
create table a(id int, age float);
insert into a values(3, 1.2);
update a set age=30.1 where id=3;
update a set id=4 where age=30.1;
update j1 set age=30 where id=3;
update j1 set age="31" where id=2;

show tables;
create table person(id int, height float, name char, birthday date);
create index date_index on person(birthday);
insert into person values(0, 1.73, 't1', '2020-01-1');
insert into person values(1, 1.78, 't2', '2020-1-01');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(2, 1.51, 't4', '3999-06-17');
insert into person values(3, 1.83, 't4', '2001-08-11');
insert into person values(4, 1.71, 't5', '1999-06-17');
insert into person values(5, 1.83, 't6', '2001-08-11');
create index name_index on person(birthday);
select * from person where birthday='1999-01-13';
create index name1_index on person(name);

-- Order by test
create unique index name_index on person(name);
insert into person values(1, 1.78, 't2', '1999-03-15'),(2, 1.78, 't2', '1999-10-15'),(3, 1.83, 't4', '2001-08-11'),(4, 1.71, 't5', '1999-06-17'),(5, 1.83, 't6', '2001-08-11');
select * from person order by height asc;
select * from person order by person.idd,height asc;
select * from person order by name asc,id asc,height,birthday;
select * from person;
drop table person;
create table person(id int, height float, name char, birthday date);
select * from person;
select min(birthday) from person;

insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(0, 1.73, 't1', '1999-01-13'),(1, 1.56, 't2', '1999-03-15'),(2, 1.51, 't3', '1999-06-17');


update person set id=0 where name='t1';
update person set height=5.2 where name='t1';
update person set birthday='1999-08-14' where name='t1';
update person set height=4.1 where id=0;
update person set height=40.0 where birthday='1999-06-17';

create index id_index on j1(id);

create unique index id_index on j2(id);

create table t (id int, name char, col1 int, col2 int);
create index i_id on t (id);
select * from t;
insert into t values(1,'t2',2,3);
insert into t values(3,'t3', 3,4);
insert into t values(3,'t3', 4,4);
update t set name='abc' where id=1;
insert into t values(3,'t3', 4,4);
update t set name='a' where col1>2;
update t set id=4 where name='abc';
update t set name='abcd' where col1=2 and col2=3;

update t set col1=100;
select * from t;
update t set name2='abc' where id=1;
update t set name='abc' where id='a';


-- Aggregate test
select max(id) from person;
select max(height) from person;
select max(birthday) from person;
select min(id) from person;
select min(height) from person;
select min(birthday) from person;
select avg(height) from person;
select avg(id) from person;
select min(id),min(height) from person;
select max(id),min(height) from person;
select max(id),min(id) from person;
select max(id),avg(height),max(birthday) from person;
select max(name) from person;
select min(name) from person;
select count(id) from person;
select count(*) from person;
select count() from person;
select max(*) from person;
select min(*) from person;
SELECT count(height,id) FROM person;
SELECT avg() FROM person;
SELECT avg(*) FROM person;
select avg(birthday) from person;
select min(birthday) from person;
select max(birthday) from person;
select avg(birthday) from person;
select count(birthday) from person;


-- Unique test
create table person(id int, height float, name char, birthday date);
create unique index id_index on person(id);
create index id_index on person(height);
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(4, 1.51, 't3', '1999-06-17');
insert into person values(9, 1.83, 't4', '2001-08-11');
drop table person;
create table person(id int, height float, name char, birthday date);
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(3, 1.83, 't4', '2001-08-11');
create unique index id_index on person(id);
drop table person;

unique: result file difference(`-` is yours and `+` is base)
 1. UNIQUE TEST
CREATE UNIQUE INDEX INDEX_ID ON UNIQUE_TABLE(ID);
SUCCESS
INSERT INTO UNIQUE_TABLE VALUES (2,1,1);
-FAILURE
+SUCCESS
CREATE UNIQUE INDEX INDEX_ID ON UNIQUE_TABLE(ID);
FAILURE
INSERT INTO UNIQUE_TABLE VALUES (3,2,1);
-FAILURE
+SUCCESS
 INSERT INTO UNIQUE_TABLE VALUES (1,2,1);
 FAILURE




-- Group by test
drop table person;
create table person(id int, height float, name char, birthday date);
insert into person values(0, 1.73, 't1', '1999-01-13'),(1, 1.78, 't2', '1999-03-15');
insert into person values(1, 1.93, 't2', '1999-03-25'),(1, 1.51, 't4', '1899-03-17');
insert into person values(2, 1.51, 't4', '1899-03-17'),(2, 1.61, 't4', '1999-06-19');
insert into person values(2, 1.21, 't4', '1999-06-27'),(0, 1.83, 't4', '2001-08-11');
insert into person values(3, 1.21, 'C', '1999-06-27'),(3, 1.83, 'C', '2001-08-11');
insert into person values(3, 1.21, 'C', '1999-06-27'),(3, 1.83, 'C', '2001-08-11');
insert into person values(3, 1.21, 'C', '1999-06-27'),(3, 1.83, 'C', '2001-08-11');
insert into person values(3, 1.21, 'C', '1999-06-27'),(3, 1.83, 'C', '2001-08-11');
insert into person values(3, 1.83, 't4', '2001-08-11');

select avg(height) from person group by id;
select id,avg(height) from person group by id;
select id,name,avg(height) from person group by id,name;
select id,name,min(height),max(height),avg(height) from person group by id,name;

create index id_index on person(id);
create index name_index on person(name);
select * from person;
select id,avg(height) from person group by id;
SELECT id,name, AVG(height) FROM person GROUP BY id,name;

select id,name,max(height) from person group by id,name;

create table gr(id int, name char, col2 int);
create index id_index on gr(id);
create index name_index on gr(name);
create index col_index on gr(col2);
insert into gr values(1, 'A', 2),(1, 'A', 14);
insert into gr values(1, 'B', 12),(2, 'A', 11);
insert into gr values(2, 'A', 14),(2, 'C', 19);
insert into gr values(3, 'C', 17),(3, 'C', 14);
insert into gr values(3, 'B', 12),(3, 'A', 11);
insert into gr values(2, 'C', 17),(2, 'A', 29);
select id,name,avg(col2) from gr GROUP BY name,id;

group-by: result file difference(`-` is yours and `+` is base)
SELECT ID, NAME, AVG(SCORE) FROM T_GROUP_BY GROUP BY ID, NAME;
1 | B | 2
 3 | A | 1
-3 | C | 2
-3 | C | 4
+3 | C | 3
 3 | D | 3
 3 | F | 2
 4 | C | 3
 ID | NAME | AVG(SCORE)

3. PRIMARY GROUP BY
SELECT ID, AVG(SCORE) FROM T_GROUP_BY GROUP BY ID;
-1 | 3
-3 | 0.2
-4 | 2
+1 | 2
+3 | 2.4
+4 | 3
 ID | AVG(SCORE)

-- inner join
create table t1(id int, col1 int, feat1 float);
create table t2(id int, col2 int, feat2 float);
create table t3(id int, col2 int, feat2 float);
insert into t1 values(1, 4, 11.2),(2, 2, 12.0),(3, 3, 13.5);
insert into t2 values(1, 2, 13.0),(2, 7, 10.5),(5, 3, 12.6);
insert into t3 values(1, 2, 13.0),(6, 7, 10.5),(5, 3, 12.6);
select * from t1 inner join t2 on t1.id=t2.idd;
select t2.feat2 from t1 inner join t2 on t1.id=t2.idd;
select * from t1 inner join t2 on t1.id=t2.idd inner join t3 on t1.id=t3.id;
select * from t1,t2,t3 where t1.id=t2.idd and t1.id=t3.id;
select * from t1 inner join t2 on t1.id=t2.idd and t2.col2>5 where t1.id >=2;


join-tables: result file difference(`-` is yours and `+` is base)
SELECT JOIN_TABLE_1.NAME FROM JOIN_TABLE_1 INNER JOIN JOIN_TABLE_2 ON JOIN_TABLE_1.ID=JOIN_TABLE_2.ID;
A
B
 JOIN_TABLE_1.NAME
SELECT JOIN_TABLE_2.NUM FROM JOIN_TABLE_1 INNER JOIN JOIN_TABLE_2 ON JOIN_TABLE_1.ID=JOIN_TABLE_2.ID;
15
 2
 JOIN_TABLE_2.NUM
SELECT * FROM JOIN_TABLE_1 INNER JOIN JOIN_TABLE_2 ON JOIN_TABLE_1.ID=JOIN_TABLE_2.ID INNER JOIN JOIN_TABLE_3 ON JOIN_TABLE_1.ID=JOIN_TABLE_3.ID;
1 | A | 1 | 2 | 1 | 120
-1 | A | 1 | 2 | 3 | 800
-2 | B | 2 | 15 | 1 | 120
-2 | B | 2 | 15 | 3 | 800
 JOIN_TABLE_1.ID | JOIN_TABLE_1.NAME | JOIN_TABLE_2.ID | JOIN_TABLE_2.NUM | JOIN_TABLE_3.ID | JOIN_TABLE_3.NUM2
SELECT * FROM JOIN_TABLE_1 INNER JOIN JOIN_TABLE_2 ON JOIN_TABLE_1.ID=JOIN_TABLE_2.ID AND JOIN_TABLE_2.NUM>13 WHERE JOIN_TABLE_1.NAME='B';
2 | B | 2 | 15
 JOIN_TABLE_1.ID | JOIN_TABLE_1.NAME | JOIN_TABLE_2.ID | JOIN_TABLE_2.NUM
SELECT * FROM JOIN_TABLE_1 INNER JOIN JOIN_TABLE_2 ON JOIN_TABLE_1.ID=JOIN_TABLE_2.ID AND JOIN_TABLE_2.NUM>13 WHERE JOIN_TABLE_1.NAME='A';
JOIN_TABLE_1.ID | JOIN_TABLE_1.NAME | JOIN_TABLE_2.ID | JOIN_TABLE_2.NUM
SELECT * FROM JOIN_TABLE_1 INNER JOIN JOIN_TABLE_2 ON JOIN_TABLE_1.ID=JOIN_TABLE_2.ID AND JOIN_TABLE_2.NUM>23 WHERE JOIN_TABLE_1.NAME='B';
JOIN_TABLE_1.ID | JOIN_TABLE_1.NAME | JOIN_TABLE_2.ID | JOIN_TABLE_2.NUM





-- sub select
create table t1(id int, col1 int, feat1 float);
create table t2(idd int, col2 int, feat2 float);
insert into t1 values(1, 4, 11.2),(2, 2, 12.0),(3, 3, 13.5);
insert into t1 values(4, 61, 16.5),(5, 16, 19.2)
insert into t1 values(6, 45, 11.3),(7, 78, 21.1),(8, 24, 25.2),(9, 61, 16.5),(10, 16, 19.2);

insert into t2 values(1, 2, 13.0),(2, 7, 10.5),(5, 3, 12.6);
insert into t2 values(1, 17, 14.1),(2, 16, 25.6),(3, 24, 23.4),(4, 11, 29.6);

select * from t1 where t1.col1 >(select avg(col2) from t2);
select avg(height) from t2;
select * from t1 where t1.height > 5.39;
select * from t1 where t1.id < (select avg(idd) from t2);
select * from t1 where id in (select t2.idd from t2);
select id,col1 from t1 where col1 NOT IN (select col2 from t2);
select * from t1 where col1 IN (select col2 from t2);
select * from t1 where height > 2;
create index col2_index on t2(col2);
create index col1_index on t1(col1);
create index id_index on t1(id);
create index id_index on t2(idd);
select * from t2 where col2 IN (select t1.col1 from t1);
select * from t1 where id NOT IN (select max(t2.idd) from t2);
select max(t2.idd) from t2;


simple-sub-query: result file difference(`-` is yours and `+` is base)
 1. SELECT
SELECT * FROM t1 WHERE id IN (SELECT t2.idd FROM t2);
1 | 4 | 11.2
 2 | 2 | 12
 ID | COL1 | FEAT1
SELECT * FROM t1 WHERE col1 NOT IN (SELECT t2.col2 FROM t2);
+1 | 4 | 11.2
+ID | COL1 | FEAT1

create table person1(id int, height float, name char, birthday date);
create table person2(id int, height float, name char, birthday date);
insert into person1 values(0, 1.73, 't1', '1999-01-13'),(1, 1.78, 't2', '1999-03-15'),(2, 1.78, 't3', '1999-03-15');
insert into person2 values(0, 1.73, 't1', '1999-01-13'),(1, 1.83, 't2', '1999-03-15'),(3, 2.1, 't4', '1999-03-15');
create index id_index on person1(id);
create index id_index on person2(id);
create index name_index on person1(name);
create index name_index on person2(name);
select * from person1 where name NOT IN (select person2.name from person2);
select * from person2 where name NOT IN (select person1.name from person1);
select * from person1 where (select max(person2.id) from person2) < id;
--multi-index
create table t1(id int, age int, feat1 float);
create table t2(id int, age int, feat1 float);
insert into t1 values(1, 45, 21.1);
insert into t1 values(2, 47, 21.1);
insert into t1 values(7, 234, 31.1);
insert into t1 values(1, 45, 11.3),(2, 78, 21.1),(3, 24, 25.2),(4, 61, 16.5),(5, 16, 19.2);
insert into t1 values(6, 45, 11.3),(7, 78, 21.1),(3, 24, 25.2);
insert into t2 values(1, 17, 14.1),(2, 16, 25.6),(3, 24, 23.4),(4, 11, 29.6);
create index i_id_age on t1(id, age);
select * from t1;
select * from t1 where age = 45;
select * from t1 where id=1 and age = 50;
update t1 set age=50 where id=1;
create index i_id_age_feat on t1(id, age,feat1);

create table person(id int, height float, name char, birthday date);
create index i_id_age on person(height, name);
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
DELETE FROM person WHERE height = 1.78 AND name = 't2';
insert into person values(1, 1.93, 't2', '1999-03-25');
insert into person values(2, 1.51, 't4', '1899-03-17');
insert into person values(2, 1.61, 't4', '1999-06-19');
insert into person values(2, 1.21, 't4', '1999-06-27');
insert into person values(3, 1.83, 't4', '2001-08-11');
-- null
insert into person values(4, 1.71, 't5', '1999-06-17');
insert into person values(5, 1.83, 't6', '2001-08-11');
select * from person order by id;

create table t1 (id int not null, age int nullable, address char nullable, birthday date nullable);
insert into t1 values(1, 2, 'OK','1999-01-13'),(2,null,'OKK',null),(3,4,'OKKK',null ),(4,null,null,'2001-08-11');
select * from t1 where age=2;
select * from t1 where age is not null;
select count(*) from t1;
select count(age) from t1;
select avg(age) from t1;

update t1 set age = 1 where address is null;
select * from t1 where t1.birthday is null;
select * from t1 where t1.age is null;
create index age_index on t1(age);

create table t1(id int,num int nullable,birthday date nullable);
insert into t1 values(1,1,"2020-1-19"),(2,2,"2009-6-9"),(3,null,"1999-10-3"),(4,4,null),(5,null,null);

create table t2(id int,name char nullable,birthday date nullable);
insert into t2 values(1,"aaa","2020-1-19"),(2,"bbb","1987-4-5"),(3,null,null),(4,null,"2021-10-30"),(5,"eee",null);

select * from t1,t2 where t1.birthday>t2.birthday;

create table text_table2(id int,name text);
create table text_table(id int,name text);
insert into text_table values(1,"this is a long text"),(3,"this is also a long text");
select * from text_table where name < 'this';
create index name_index on text_table(name);

update text_table set name = 'wowowowowowowo' where id=1;

INSERT INTO TEXT_TABLE VALUES (5,'THIS IS A VERY VERY LONG STRING PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD PAD1 PAD PAD PAD PAD');


