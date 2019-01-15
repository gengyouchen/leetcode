class Solution {
public:
	/* time: O(n), space: O(1) */
	int rob(const vector<int>& nums) {
		if (nums.empty())
			return 0;
		const int n = nums.size();
		if (n == 1)
			return nums[0];

		int _dp[3];
		auto dp = [&](int i) -> int& { return _dp[i % 3]; };

		int ans = 0;
		auto robRange = [&](int first, int last) {
			for (int i = first; i < last; ++i) {
				if (i == first)
					dp(i) = nums[i];
				else if (i == first + 1)
					dp(i) = max(dp(i - 1), nums[i]);
				else
					dp(i) = max(dp(i - 1), dp(i - 2) + nums[i]);
				ans = max(ans, dp(i));
			}
		};
		robRange(0, n - 1), robRange(1, n);
		return ans;
	}
};
