class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	static vector<int> countBits(int num) {
		const int n = num + 1;
		vector<int> dp(n);

		int len = 1;
		for (int i = 1; i < n; ++i) {
			const int j = i - len; /* remove MSB */
			dp[i] = dp[j] + 1;
			if (j == len - 1)
				len *= 2;
		}
		return dp;
	}
};
