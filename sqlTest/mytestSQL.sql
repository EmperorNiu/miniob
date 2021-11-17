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
create index id_index on person(id);
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
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
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(3, 1.83, 't4', '2001-08-11');
drop table person;
create table person(id int, height float, name char, birthday date);
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(3, 1.83, 't4', '2001-08-11');
create unique index id_index on person(id);
drop table person;


-- Group by test
drop table person;
create table person(id int, height float, name char, birthday date);
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
insert into person values(1, 1.93, 't2', '1999-03-25');
insert into person values(2, 1.51, 't4', '1899-03-17');
insert into person values(2, 1.61, 't4', '1999-06-19');
insert into person values(2, 1.21, 't4', '1999-06-27');
insert into person values(3, 1.83, 't4', '2001-08-11');
select avg(height) from person group by id;

-- sub select
create table t1(id int, col1 int, feat1 float);
create table t2(idd int, col2 int, feat2 float);
insert into t1 values(1, 45, 11.3),(2, 78, 21.1),(3, 24, 25.2),(4, 61, 16.5),(5, 16, 19.2);
insert into t2 values(1, 17, 14.1),(2, 16, 25.6),(3, 24, 23.4),(4, 11, 29.6);
select * from t1 where t1.height > (select avg(col2) from t2);
select avg(height) from t2;
select * from t1 where t1.height > 5.39;
select * from t1 where t1.id < (select avg(idd) from t2);
select * from t1 where id in (select t2.idd from t2);
select * from t1 where col1 NOT IN (select col2 from t2);
select * from t1 where col1 IN (select col2 from t2);
select * from t1 where height > 2;
create index col2_index on t2(col2);
create index col1_index on t1(col1);
create index id_index on t1(id);
create index id_index on t2(idd);
select * from t2 where col2 IN (select t1.col1 from t1);
select * from t1 where id NOT IN (select t2.idd from t2);

simple-sub-query: result file difference(`-` is yours and `+` is base)
 1. SELECT
SELECT * FROM SSQ_1 WHERE ID IN (SELECT SSQ_2.ID FROM SSQ_2);
1 | 4 | 11.2
 2 | 2 | 12
 ID | COL1 | FEAT1
SELECT * FROM SSQ_1 WHERE COL1 NOT IN (SELECT SSQ_2.COL2 FROM SSQ_2);
+1 | 4 | 11.2
+ID | COL1 | FEAT1

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




