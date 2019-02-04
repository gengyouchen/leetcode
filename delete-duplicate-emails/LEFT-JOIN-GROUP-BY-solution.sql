DELETE Person.*
FROM Person
LEFT JOIN (SELECT Min(Id) AS Id FROM Person GROUP BY Email) Remained
	ON Person.Id = Remained.Id
WHERE Remained.Id IS NULL;
