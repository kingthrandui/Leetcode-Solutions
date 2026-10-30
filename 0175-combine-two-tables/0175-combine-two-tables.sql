# Write your MySQL query statement below
select p.lastName , p.firstName , city , state from Person as p LEFT JOIN
Address as a on p.personId = a.personId