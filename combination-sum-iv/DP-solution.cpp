class Solution {
public:
	/*
	 * time: O(target * len(nums)), space: O(target)
	 *
	 * Strictly speaking, this problem should not be named as the "Combination" Sum
	 * because different sequences are counted as different combinations.
	 * This problem is actually the "Permutation" Sum.
	 *
	 * For the real "Combination" Sum problem, see LeetCode 518 - Coin Change 2
	 */
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
