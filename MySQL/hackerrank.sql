--  Basic Select

-- Revising the Select Query - 1
select * from city where population > 100000 and countrycode = "USA";

--  Revising the Select Query - 2
select name from city where population > 120000 and countrycode = "USA";

-- Select All
select * from city;

-- Select by ID
select * from city where id = 1661;

--Japanese Cities' Detail
select * from city where countrycode="JPN";

-- Japanese Cities' Name
select name from city where countrycode="JPN";

-- Weather Observation Station 1
select city, state from station;

-- Weather Observation Station 3
select distinct city from station where id%2=0;
