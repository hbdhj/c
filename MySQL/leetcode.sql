
-- 175. Combine Two Tables
SELECT FirstName, LastName, City, State FROM Person LEFT OUTER JOIN Address ON Person.PersonId = Address.PersonId;

-- 176. Second Highest Salary
SELECT MAX(Salary) FROM Employee WHERE Salary <> (SELECT MAX(Salary) FROM Employee);

-- 181. Employees Earning More Than Their Managers
SELECT Name FROM Employee AS A WHERE Salary>(SELECT Salary FROM Employee AS B WHERE Id = A.ManagerId);

-- 182. Duplicate Emails
select distinct p1.Email from Person p1, Person p2 where p1.Email=p2.Email and p1.Id!=p2.Id ;

-- 183. Customers Who Never Order
SELECT Name FROM Customers WHERE id NOT IN (SELECT CustomerId FROM Orders);

-- 197. Rising Temperature
SELECT w1.Id FROM Weather w1, Weather w2 WHERE w2.Date = DATE_SUB(w1.Date, INTERVAL 1 DAY) AND w1.Temperature > w2.Temperature;

-- 196. Delete Duplicate Emails
DELETE P2 FROM Person AS P1, Person AS P2 WHERE  P1.Email = P2.Email AND P1.Id < P2.Id;

-- 596. Classes More Than 5 Students
SELECT class FROM (SELECT class, COUNT(DISTINCT student) AS num FROM courses GROUP BY class) AS temp_table WHERE num >= 5;

-- 620. Not Boring Movies
select * from cinema where mod(id, 2) = 1 and description != 'boring' order by rating DESC;

-- 627. Swap Salary
UPDATE salary SET sex = CASE sex WHEN 'm' THEN 'f' ELSE 'm' END;
