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
insert into t3 values(1, "2021-2-28");
update t3 set age="2021-3-28" where id=1;
update t3 set id=20 where age="2021-03-28";
create table a(id int, age float);
insert into a values(1, 1.203001);

update j1 set age=30 where id=2;
update j1 set age="31" where id=2;

select * from t3 where age = '2021-2-28';

insert into t3 values(2, "2021-3-28");