SELECT
    Department.Name AS Department,
    Employee.Name AS Employee,
    Salary
FROM
    Employee
    NATURAL JOIN (
        SELECT
            Salary, DepartmentId,
            @count:=IF(@prev<=>DepartmentId, @count+1, 0) AS Rank,
            @prev:=DepartmentId
        FROM
            (SELECT DISTINCT Salary, DepartmentId FROM Employee) DistinctSalaries,
            (SELECT @count:=0, @prev:=NULL) RowInfo
        ORDER BY DepartmentId, Salary DESC
    ) Ranks
    JOIN Department
        ON DepartmentId = Department.Id
WHERE Rank < 3
ORDER BY DepartmentId, Salary DESC;
