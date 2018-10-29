class Solution {
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count input itself) */
	int minPathSum(vector<vector<int>>& grid) {
		const int m = grid.size(), n = grid[0].size();
		auto dp = [&](int i, int j) -> int& { return grid[i][j]; };
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (i == 0 && j == 0)
					dp(i, j) = grid[i][j];
				else if (i == 0)
					dp(i, j) = grid[i][j] + dp(i, j - 1);
				else if (j == 0)
					dp(i, j) = grid[i][j] + dp(i - 1, j);
				else
					dp(i, j) = grid[i][j] + min(dp(i - 1, j), dp(i, j - 1));
		return dp(m - 1, n - 1);
	}
};
