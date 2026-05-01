# Write your MySQL query statement below
SELECT firstname, lastname, city, state FROM Person as P LEFT JOIN Address as A ON (P.personID = A.personID);
