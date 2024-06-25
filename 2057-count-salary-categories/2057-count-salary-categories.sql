WITH AllCategories AS (
    SELECT 'Low Salary' AS CATEGORY
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
),
CategorizedAccounts AS (
    SELECT
        CASE
            WHEN INCOME < 20000 THEN 'Low Salary'
            WHEN INCOME >= 20000 AND INCOME <= 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS CATEGORY
    FROM ACCOUNTS
)
SELECT 
    ac.CATEGORY, 
    COUNT(ca.CATEGORY) AS accounts_count
FROM  AllCategories ac
LEFT JOIN CategorizedAccounts ca ON ac.CATEGORY = ca.CATEGORY
GROUP BY ac.CATEGORY