SELECT Score, Rank
FROM (
	SELECT
		Score,
		@count:=CAST(@count AS UNSIGNED)+IF(@prev<=>Score, 0, 1) AS Rank,
		@prev:=Score
	FROM
		Scores,
		(SELECT @count:=0, @prev:=NULL) RowInfo
	ORDER BY Score DESC
) Ranks;
