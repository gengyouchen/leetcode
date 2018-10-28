class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> generateMatrix(int n) {
		auto val = [&](int row, int col) {
			const int iLoop = min(min(row, (n - 1) - row), min(col, (n - 1) - col));
			const int sideLen = n - iLoop * 2;

			const int r0 = iLoop, c0 = iLoop;
			const int r1 = iLoop, c1 = iLoop + (sideLen - 1);
			const int r2 = iLoop + (sideLen - 1), c2 = iLoop + (sideLen - 1);
			const int r3 = iLoop + (sideLen - 1), c3 = iLoop;

			const int val0 = 1 + (n * n - sideLen * sideLen);
			const int val1 = val0 + (sideLen - 1);
			const int val2 = val1 + (sideLen - 1);
			const int val3 = val2 + (sideLen - 1);

			if (row == r0)
				return val0 + (col - c0);
			else if (col == c1)
				return val1 + (row - r1);
			else if (row == r2)
				return val2 + (c2 - col);
			else
				return val3 + (r3 - row);
		};

		vector<vector<int>> ans(n, vector<int>(n));
		for (int row = 0; row < n; ++row)
			for (int col = 0; col < n; ++col)
				ans[row][col] = val(row, col);
		return ans;
	}
};
