class Solution {
public:
	/* time: O(m * n^2), space: O(n) */
	static int splitArray(const vector<int>& nums, int m) {
		const int n = nums.size();
		using LL = long long;
		vector<LL> prefix(n + 1);
		for (int i = 1; i <= n; ++i)
			prefix[i] = prefix[i - 1] + nums[i - 1];

		vector<vector<LL>> _dp(2, vector<LL>(n + 1));
#define DP(k, len) _dp[(k) % 2][len]
		for (int k = 1; k <= m; ++k) {
			for (int len = k; len <= n; ++len) {
				if (k == 1) {
					DP(k, len) = prefix[len] - prefix[0];
				} else {
					DP(k, len) = INT_MAX;
					for (int i = k - 1; i < len; ++i)
						DP(k, len) = min(DP(k, len), max(DP(k - 1, i), prefix[len] - prefix[i]));
				}
			}
		}
		return DP(m, n);
#undef DP
	}
};
