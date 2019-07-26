class Solution {
public:
	/* time: O(n), space: O(1) */
	static bool increasingTriplet(const vector<int>& nums) {
		/*
		 * Reduce this problem to LeetCode 300 - Longest Increasing Subsequence.
		 * Use its binary search DP approach.
		 *
		 * To achieve O(n) time, O(1) space, we can limit the size of the DP array <= 3
		 * because we don't care any longer increasing subsequences.
		 */
		vector<int> dp;
		for (int num : nums) {
			const auto it = lower_bound(dp.begin(), dp.end(), num);
			if (it == dp.end())
				dp.push_back(num);
			else
				*it = num;
			if (dp.size() == 3)
				return true;
		}
		return false;
	}
};
