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
		const int n = nums.size();
		vector<int> dp(n, 1);

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
public:
	/* time: O(n^2), space: O(n) */
	static int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		auto comp = [](const auto& a, const auto& b) {
			return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);
		};
		sort(envelopes.begin(), envelopes.end(), comp);

		const int n = envelopes.size();
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
			nums[i] = envelopes[i].second;
		return lengthOfLIS(nums);
	}
};
