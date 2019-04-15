class Solution {
private:
	/*
	 * This problem can be reduced to LIS (Longest Increasing Sub-sequence) problem.
	 * See LeetCode 300 - Longest Increasing Subsequence.
	 *
	 * In LIS problem, if we treat each number's index as w, and each number's value as h,
	 * then:
	 * 1. Any sub-sequence { a, b, c, ...} will satisfy w[a] < w[b] < w[c] < ...
	 * 2. Any increasing sub-sequence { a, b, c, ...} will satisfy h[a] < h[b] < h[c] < ...
	 */
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
public:
	/* time: O(n*log(n)), space: O(n) */
	static int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
				return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);
				});
		const int n = envelopes.size();
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
			nums[i] = envelopes[i].second;
		return lengthOfLIS(nums);
	}
};
