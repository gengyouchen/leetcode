class Solution {
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count input itself) */
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		auto dp = [&](int i, int j) -> int& { return obstacleGrid[i][j]; };
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (i == 0 && j == 0)
					dp(i, j) = obstacleGrid[i][j] ? 0 : 1;
				else if (i == 0)
					dp(i, j) = obstacleGrid[i][j] ? 0 : dp(i, j - 1);
				else if (j == 0)
					dp(i, j) = obstacleGrid[i][j] ? 0 : dp(i - 1, j);
				else
					dp(i, j) = obstacleGrid[i][j] ? 0 : (dp(i - 1, j) + dp(i, j - 1));
		return dp(m - 1, n - 1);
	}
};
