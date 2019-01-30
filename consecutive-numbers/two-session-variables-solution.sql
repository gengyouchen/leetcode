SELECT DISTINCT Num AS ConsecutiveNums
FROM (
	SELECT
		Num,
		@count:=+IF(@prev<=>Num, @count+1, 1) AS ConsecutiveCount,
		@prev:=Num
	FROM
		Logs,
		(SELECT @prev:=NULL, @count:=1) RowInfo
	ORDER BY Id
) ConsecutiveCounts
WHERE ConsecutiveCount >= 3;
