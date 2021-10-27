create table t(id int, age int);
drop table t;
create table t(id int, name int);
insert into t values(2, 22);
insert into t values(4, 53);
select * from t;
update t set name = 200 where id>1;
select * from t;

create table j1(id int, age int);
create table j2(id int, age int);
create table j3(id int, age int);
insert into j1 values(1, 24);
insert into j1 values(2, 22);
insert into j2 values(2, 24);
insert into j2 values(4, 53);
insert into j3 values(5, 53);
select * from j1,j2;
select * from j1,j2,j3;
select * from j1,j2 where j1.id=j2.id and j1.age > 10;
select * from j1,j2 where j1.id=j2.id;
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
insert into person values(0, 1.73, 't1', '1999-01-13');
insert into person values(1, 1.78, 't2', '1999-03-15');
insert into person values(2, 1.51, 't3', '1999-06-17');
insert into person values(3, 1.83, 't4', '2001-08-11');
select * from person;
drop table person;
create table person(id int, height float, name char, birthday date);
select * from person;
select min(birthday) from person;

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
update t set name='abcd' where col1=100 and col2=3;
update t set name='abcd' where col1=2100 and col2=3;