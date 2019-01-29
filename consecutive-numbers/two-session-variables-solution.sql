SELECT DISTINCT Num AS ConsecutiveNums
FROM (
	SELECT
		Num,
		CASE
			WHEN @prev=Num THEN @count:=@count+1
			WHEN @prev:=Num THEN @count:=1
		END ConsecutiveCount
	FROM
		Logs,
		(SELECT @prev:=NULL, @count:=1) RowInfo
	ORDER BY Id
) ConsecutiveCounts
WHERE ConsecutiveCount >= 3;
