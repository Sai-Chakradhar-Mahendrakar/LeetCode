# Write your MySQL query statement below
SELECT 
    MAX(NUM) AS NUM
FROM MYNUMBERS
WHERE NUM IN (
    SELECT NUM 
    FROM MYNUMBERS 
    GROUP BY NUM 
    HAVING COUNT(*)=1
    )
