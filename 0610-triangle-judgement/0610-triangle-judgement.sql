# Write your MySQL query statement below
SELECT X, Y, Z,
    (
        CASE 
            WHEN X+Y>Z AND Y+Z>X AND X+Z>Y THEN 'Yes'
            ELSE 'No'
        END
    ) AS TRIANGLE
FROM TRIANGLE