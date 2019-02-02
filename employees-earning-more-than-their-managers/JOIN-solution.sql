SELECT
	Employees.Name AS Employee
FROM Employee AS Employees
	JOIN Employee AS Managers
		ON Employees.ManagerId = Managers.Id AND Employees.Salary > Managers.Salary;
