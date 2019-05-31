class NumMatrix {
private:
	vector<vector<int>> BIT;
	static int lowbit(int x) { return x & -x; }
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count Fenwick tree itself) */
	NumMatrix(const vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		const int m = matrix.size(), n = matrix[0].size();
		BIT.resize(m + 1);
		for (auto& row : BIT)
			row.resize(n + 1);
		for (int i = 0; i < m; ++i)
			copy(matrix[i].begin(), matrix[i].end(), BIT[1 + i].begin() + 1);
		auto build1D = [&](int size, auto at) {
			for (int x = 1; x < size; ++x) {
				if (x + lowbit(x) < size)
					at(x + lowbit(x)) += at(x);
			}
		};
		for (int i = 1; i <= m; ++i)
			build1D(n + 1, [&](int x) -> int& { return BIT[i][x]; });
		for (int i = 1; i <= n; ++i)
			build1D(m + 1, [&](int x) -> int& { return BIT[x][i]; });
	}
	/* time: O(log(m)*log(n)), space: O(1) auxiliary (i.e. does not count Fenwick tree itself) */
	void update(int row, int col, int val) {
		const int m = BIT.size(), n = BIT[0].size();
		const int diff = val - sumRegion(row, col, row, col);
		for (int i = 1 + row; i < m; i += lowbit(i)) {
			for (int j = 1 + col; j < n; j += lowbit(j))
				BIT[i][j] += diff;
		}
	}
	/* time: O(log(m)*log(n)), space: O(1) auxiliary (i.e. does not count Fenwick tree itself) */
	int sumRegion(int row1, int col1, int row2, int col2) const {
		auto S = [&](int row, int col) {
			int sum = 0;
			for (int i = 1 + row; i > 0; i -= lowbit(i)) {
				for (int j = 1 + col; j > 0; j -= lowbit(j))
					sum += BIT[i][j];
			}
			return sum;
		};
		return S(row2, col2) + S(row1 - 1, col1 - 1) - S(row2, col1 - 1) - S(row1 - 1, col2);
	}
};
