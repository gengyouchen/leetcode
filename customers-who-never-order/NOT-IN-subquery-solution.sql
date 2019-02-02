SELECT Name AS Customers
FROM Customers
WHERE Customers.Id NOT IN (SELECT DISTINCT CustomerId FROM Orders);
