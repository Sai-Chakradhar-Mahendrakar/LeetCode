SELECT IFNULL(
    (
        SELECT DISTINCT SALARY
        FROM EMPLOYEE
        ORDER BY SALARY DESC
        LIMIT 1 OFFSET 1
    ), NULL
) AS SecondHighestSalary;
