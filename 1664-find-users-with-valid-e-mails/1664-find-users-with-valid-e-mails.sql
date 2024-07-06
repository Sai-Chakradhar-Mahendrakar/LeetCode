# Write your MySQL query statement below
SELECT *
FROM USERS
WHERE MAIL REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]com$';
