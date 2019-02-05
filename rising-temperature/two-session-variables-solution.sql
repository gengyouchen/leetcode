SELECT Id
FROM (
	SELECT
		Id,
		IF(Temperature > @prevT && DATEDIFF(RecordDate, @prevD) = 1, 1, 0) AS Rising,
		@prevT:=Temperature,
		@prevD:=RecordDate
	FROM
		Weather,
		(SELECT @prevT:=NULL, @prevD:=NULL) RowInfo
	ORDER BY RecordDate ASC
) RisingWeather
WHERE Rising = 1;
