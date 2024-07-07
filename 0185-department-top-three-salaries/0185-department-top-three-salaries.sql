SELECT
    D.name AS Department,
    E.name AS Employee,
    E.salary AS Salary
FROM (
    SELECT
        id,
        name,
        salary,
        departmentId,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
) AS E
JOIN Department D ON E.departmentId = D.id
WHERE E.rnk <= 3
ORDER BY Department, Salary DESC, Employee;
