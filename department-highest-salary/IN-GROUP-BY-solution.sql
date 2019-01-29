SELECT
	Department.name AS 'Department',
	Employee.name AS 'Employee',
	Salary
FROM Employee
	JOIN Department
		ON DepartmentId = Department.Id
WHERE (DepartmentId , Salary) IN (
	SELECT DepartmentId, MAX(Salary)
	FROM Employee
	GROUP BY DepartmentId
);
