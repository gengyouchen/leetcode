class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	static vector<int> countBits(int num) {
		const int n = num + 1;
		vector<int> dp(n);
		for (int i = 1; i < n; ++i) {
			const int j = i & (i - 1); /* remove lowbit */
			dp[i] = dp[j] + 1;
		}
		return dp;
	}
};
