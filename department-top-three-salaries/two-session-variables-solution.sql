SELECT
	Department.Name AS Department,
	Employee.Name AS Employee,
	Salary
FROM
	Employee
	NATURAL JOIN (
		SELECT Salary, DepartmentId
		FROM (
			SELECT
				Salary, DepartmentId,
				@count:=IF(@prev<=>DepartmentId, @count+1, 0) AS Rank,
				@prev:=DepartmentId
			FROM
				(SELECT DISTINCT Salary, DepartmentId FROM Employee) DistinctSalaries,
				(SELECT @count:=0, @prev:=NULL) RowInfo
			ORDER BY DepartmentId, Salary DESC
		) Ranks
		WHERE Rank < 3
	) GoodRanks
	JOIN Department
		ON DepartmentId = Department.Id
ORDER BY DepartmentId, Salary DESC;
