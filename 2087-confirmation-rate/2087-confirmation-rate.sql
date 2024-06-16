# Write your MySQL query statement below
SELECT 
    S.USER_ID,
    ROUND((SUM(IF(C.ACTION = "confirmed", 1, 0)) / COUNT(*)), 2) AS confirmation_rate
FROM SIGNUPS S
LEFT JOIN CONFIRMATIONS C ON S.USER_ID = C.USER_ID
GROUP BY S.USER_ID
