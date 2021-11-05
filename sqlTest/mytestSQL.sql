create table t(id int, age int);
drop table t;
create table t(id int, name int);
insert into t values(2, 22);
insert into t values(4, 53);
select * from t;
update t set name = 200 where id>1;
select * from t;

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
create unique index id_index on person(id);
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(2, 1.55, 't3', '3999-06-17');
insert into person values(3, 1.83, 't4', '2001-08-11');
insert into person values(4, 1.71, 't5', '1999-06-17');
insert into person values(5, 1.83, 't6', '2001-08-11');
create index name_index on person(birthday);
select * from person where birthday='1999-01-13';
create index name1_index on person(name);
create unique index name_index on person(name);
insert into person values(1, 1.78, 't2', '1999-03-15'),(2, 1.78, 't2', '1999-10-15'),(3, 1.83, 't4', '2001-08-11'),(4, 1.71, 't5', '1999-06-17'),(5, 1.83, 't6', '2001-08-11');
select * from person order by height asc;
select * from person order by person.id;
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