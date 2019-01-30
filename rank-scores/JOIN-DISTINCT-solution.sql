SELECT Score, Rank
FROM Scores NATURAL JOIN (
	SELECT
		Score,
		@row_number:=CAST(@row_number AS UNSIGNED)+1 AS Rank
	FROM
		(SELECT DISTINCT Score FROM Scores) DistinctScores,
		(SELECT @row_number:=0) RowInfo
	ORDER BY Score DESC
) Ranks
ORDER BY Score DESC
