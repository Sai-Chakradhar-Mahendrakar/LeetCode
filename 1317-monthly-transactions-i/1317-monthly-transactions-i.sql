# Write your MySQL query statement below
SELECT 
    DATE_FORMAT(TRANS_DATE,'%Y-%m') AS month, 
    COUNTRY, 
    (COUNT(*)) AS trans_count, 
    (COUNT(IF(STATE='approved',1,NULL))) AS approved_count, 
    (SUM(AMOUNT)) AS trans_total_amount, 
    (SUM(IF(STATE='approved',AMOUNT,0))) AS approved_total_amount
FROM TRANSACTIONS
GROUP BY Date_format(trans_date, '%Y-%m'), COUNTRY
