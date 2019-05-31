class NumMatrix {
private:
	vector<vector<int>> segTree;
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count segment tree itself) */
	NumMatrix(const vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		const int m = matrix.size(), n = matrix[0].size();
		int nLeafRow = 1, nLeafColumn = 1;
		while (nLeafRow < m)
			nLeafRow *= 2;
		while (nLeafColumn < n)
			nLeafColumn *= 2;
		segTree.resize(nLeafRow * 2);
		for (auto& row : segTree)
			row.resize(nLeafColumn * 2);
		for (int i = 0; i < m; ++i)
			copy(matrix[i].begin(), matrix[i].end(), segTree[nLeafRow + i].begin() + nLeafColumn);
		auto build1D = [](int nLeaf, auto at) {
			for (int x = nLeaf - 1; x; --x)
				at(x) = at(x * 2) + at(x * 2 + 1);
		};
		for (int i = nLeafColumn; i < nLeafColumn * 2; ++i)
			build1D(nLeafRow, [&](int x) -> int& { return segTree[x][i]; });
		for (auto& row : segTree)
			build1D(nLeafColumn, [&](int x) -> int& { return row[x]; });
	}
	/* time: O(log(m)*log(n)), space: O(1) auxiliary (i.e. does not count segment tree itself) */
	void update(int row, int col, int val) {
		const int m = segTree.size(), n = segTree[0].size();
		segTree[m / 2 + row][n / 2 + col] = val;
		auto update1D = [](int x, auto at) {
			while (x /= 2)
				at(x) = at(x * 2) + at(x * 2 + 1);
		};
		update1D(m / 2 + row, [&](int x) -> int& { return segTree[x][n / 2 + col]; });
		for (int i = m / 2 + row; i; i /= 2)
			update1D(n / 2 + col, [&](int x) -> int& { return segTree[i][x]; });
	}
	/* time: O(log(m)*log(n)), space: O(1) auxiliary (i.e. does not count segment tree itself) */
	int sumRegion(int row1, int col1, int row2, int col2) const {
		const int m = segTree.size(), n = segTree[0].size();
		auto sumRegion1D = [](int i, int j, auto at) {
			if (i == j)
				return at(i);
			int sum = at(i) + at(j);
			while (i / 2 != j / 2) {
				if (!(i % 2))
					sum += at(i + 1);
				if (j % 2)
					sum += at(j - 1);
				i /= 2, j /= 2;
			}
			return sum;
		};
		return sumRegion1D(m / 2 + row1, m / 2 + row2, [&](int x) {
			return sumRegion1D(n / 2 + col1, n / 2 + col2, [&](int y) { return segTree[x][y]; });
		});
	}
};
