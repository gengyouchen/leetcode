class Solution {
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count input itself) */
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		const int m = dungeon.size(), n = dungeon[0].size();

		/* Use input space to store DP table in order to achieve O(1) space */
		auto dp = [&](int i, int j) -> int& { return dungeon[i][j]; };

		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if ((i == m - 1) && (j == n - 1))
					dp(i, j) = max(1, 1 - dungeon[i][j]);
				else if (i == m - 1)
					dp(i, j) = max(1, dp(i, j + 1) - dungeon[i][j]);
				else if (j == n - 1)
					dp(i, j) = max(1, dp(i + 1, j) - dungeon[i][j]);
				else
					dp(i, j) = max(1, min(dp(i + 1, j), dp(i, j + 1)) - dungeon[i][j]);
			}
		}
		return dp(0, 0);
	}
};
