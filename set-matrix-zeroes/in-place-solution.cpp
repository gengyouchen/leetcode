class Solution {
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void setZeroes(vector<vector<int>>& matrix) {
		const int m = matrix.size(), n = matrix[0].size();

		/* First, backup the first row's status and the first col's status. */
		int firstRow = 1, firstCol = 1;
		for (int col = 0; col < n; ++col)
			if (matrix[0][col] == 0)
				firstRow = 0;
		for (int row = 0; row < m; ++row)
			if (matrix[row][0] == 0)
				firstCol = 0;

		/*
		 * Now, we can safely use first row's space to record each col's status,
		 * and can safely use first col's space to record each row's status.
		 */
		for (int row = 1; row < m; ++row)
			for (int col = 1; col < n; ++col)
				if (matrix[row][col] == 0)
					matrix[row][0] = 0, matrix[0][col] = 0;

		/* Set zero according to each row's status and each col's status. */
		for (int row = 1; row < m; ++row)
			for (int col = 1; col < n; ++col)
				if (matrix[row][0] == 0 || matrix[0][col] == 0)
					matrix[row][col] = 0;

		if (firstRow == 0)
			for (int col = 0; col < n; ++col)
				matrix[0][col] = 0;
		if (firstCol == 0)
			for (int row = 0; row < m; ++row)
				matrix[row][0] = 0;
	}
};
