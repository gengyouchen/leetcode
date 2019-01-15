class Solution {
public:
	/* time: O(n), space: O(1) */
	int rob(const vector<int>& nums) {
		if (nums.empty())
			return 0;
		const int n = nums.size();

		int _dp[3];
		auto dp = [&](int i) -> int& { return _dp[i % 3]; };

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i == 0)
				dp(i) = nums[i];
			else if (i == 1)
				dp(i) = max(dp(i - 1), nums[i]);
			else
				dp(i) = max(dp(i - 1), dp(i - 2) + nums[i]);
			ans = max(ans, dp(i));
		}
		return ans;
	}
};
