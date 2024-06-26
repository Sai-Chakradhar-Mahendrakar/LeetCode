# Write your MySQL query statement below
SELECT 
    S.MACHINE_ID, 
    ROUND(AVG(E.TIMESTAMP-S.TIMESTAMP),3) AS PROCESSING_TIME
FROM ACTIVITY S
INNER JOIN ACTIVITY E ON
        S.MACHINE_ID = E.MACHINE_ID AND
        S.PROCESS_ID = E.PROCESS_ID AND
        S.ACTIVITY_TYPE = 'start' AND E.ACTIVITY_TYPE = 'end'
GROUP BY S.MACHINE_ID;
