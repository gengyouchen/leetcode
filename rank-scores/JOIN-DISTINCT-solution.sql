SELECT Score, Rank
FROM Scores NATURAL JOIN (
	SELECT
		Score,
		@row_number:=@row_number+1 AS Rank
	FROM
		(SELECT DISTINCT Score FROM Scores) DistinctScores,
		(SELECT @row_number:=0) RowInfo
	ORDER BY Score DESC
) Ranks
ORDER BY Score DESC
