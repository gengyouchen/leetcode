SELECT
	Department.name AS 'Department',
	Employee.name AS 'Employee',
	Salary
FROM Employee
	JOIN Department
		ON DepartmentId = Department.Id
	NATURAL JOIN (
		SELECT DepartmentId, MAX(Salary) AS 'Salary'
		FROM Employee
		GROUP BY DepartmentId
	) TopSalary;
