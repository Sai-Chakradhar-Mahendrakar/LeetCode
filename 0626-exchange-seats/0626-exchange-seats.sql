# Write your MySQL query statement below
SELECT
    RANK() OVER(ORDER BY (ID-1)^1) AS ID,
    STUDENT
FROM SEAT
