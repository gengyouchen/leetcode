class Solution {
public:
	/* time: O(n^2), space: O(n) */
	int numTrees(int n) {
		int ans = 0;
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = 0;
			for (int L = 0; L <= i; ++L) {
				const int R = i - L - 1;
				dp[i] += dp[L] * dp[R];
			}
		}
		return dp[n];
	}
};
