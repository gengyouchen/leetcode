class Solution {
public:
	/* time: O(n^3), space: O(n^2) */
	static int maxCoins(const vector<int>& nums) {
		if (nums.empty())
			return 0;
		const int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				const int L = (i > 0) ? nums[i - 1] : 1;
				const int R = (j < n - 1) ? nums[j + 1] : 1;
				for (int lastMove = i; lastMove <= j; ++lastMove) {
					int coin = L * R * nums[lastMove];
					if (lastMove > i)
						coin += dp[i][lastMove - 1];
					if (lastMove < j)
						coin += dp[lastMove + 1][j];
					dp[i][j] = max(dp[i][j], coin);
				}
			}
		}
		return dp[0][n - 1];
	}
};
