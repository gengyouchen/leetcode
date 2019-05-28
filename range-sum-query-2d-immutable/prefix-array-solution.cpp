class NumMatrix {
private:
	vector<vector<int>> prefix;
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count prefix array itself) */
	NumMatrix(const vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		const int m = matrix.size(), n = matrix[0].size();
		prefix.resize(m + 1);
		for (auto& row : prefix)
			row.resize(n + 1);

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j)
				prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}
	/* time: O(1), space: O(1) auxiliary (i.e. does not count prefix array itself) */
	int sumRegion(int row1, int col1, int row2, int col2) const {
		return prefix[row2 + 1][col2 + 1] + prefix[row1][col1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1];
	}
};
