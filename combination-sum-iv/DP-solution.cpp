class Solution {
public:
	/* time: O(target * len(nums)), space: O(target) */
	int combinationSum4(const vector<int>& nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; ++i)
			for (auto num : nums)
				if (i - num >= 0)
					dp[i] += dp[i - num];
		return dp[target];
	}
};
