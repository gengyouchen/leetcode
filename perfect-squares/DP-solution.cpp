class Solution {
public:
	/* time: O(n ^ 1.5), space: O(n) */
	static int numSquares(int n) {
		static vector<int> dp;
		while (dp.size() < n + 1) {
			dp.emplace_back();
			const int i = dp.size() - 1;
			if (i == 0) {
				dp[i] = 0;
			} else {
				dp[i] = INT_MAX;
				for (int last = 1; last * last <= i; ++last) {
					const int complement = i - last * last;
					dp[i] = min(dp[i], dp[complement] + 1);
				}
			}
		}
		return dp[n];
	}
};
