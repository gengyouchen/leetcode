SELECT
	Request_at AS Day,
	ROUND(COUNT(IF(Status != 'completed', TRUE, NULL)) / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
WHERE
	Request_at BETWEEN '2013-10-01' AND '2013-10-03'
	AND Client_Id IN (SELECT Users_Id FROM Users WHERE Banned = 'No')
	AND Driver_Id IN (SELECT Users_Id FROM Users WHERE Banned = 'No')
GROUP BY Request_at;
