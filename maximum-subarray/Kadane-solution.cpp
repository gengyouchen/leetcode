class Solution {
public:
	/* time: O(n), space: O(1) */
	int maxSubArray(const vector<int>& nums) {
		int _dp;
		auto dp = [&](int i) -> int& { return _dp; };

		int ans = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			if (i == 0)
				dp(i) = nums[i];
			else
				dp(i) = max(dp(i - 1) + nums[i], nums[i]);
			ans = max(ans, dp(i));
		}
		return ans;
	}
};
