# Write your MySQL query statement below
SELECT 
    SELL_DATE,
    COUNT(DISTINCT PRODUCT) AS NUM_SOLD,
    GROUP_CONCAT(
        DISTINCT PRODUCT 
        ORDER BY PRODUCT 
        SEPARATOR ','
    ) AS PRODUCTS
FROM ACTIVITIES
GROUP BY SELL_DATE
ORDER BY SELL_DATE