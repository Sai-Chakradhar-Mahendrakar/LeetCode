# Write your MySQL query statement below
SELECT E1.UNIQUE_ID,E2.NAME
FROM EMPLOYEES E2
LEFT JOIN EMPLOYEEUNI E1 ON E1.ID = E2.ID