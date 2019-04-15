class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	static int lengthOfLIS(const vector<int>& nums) {
		vector<int> dp;
		for (int num : nums) {
			const auto it = lower_bound(dp.begin(), dp.end(), num);
			if (it == dp.end())
				dp.push_back(num);
			else
				*it = num;
		}
		return dp.size();
	}
};
