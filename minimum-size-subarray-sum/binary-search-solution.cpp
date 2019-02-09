class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	int minSubArrayLen(int s, const vector<int>& nums) {
		const int n = nums.size();
		int ans = INT_MAX;
		vector<int> S(n + 1);
		S[0] = 0;
		partial_sum(nums.begin(), nums.end(), S.begin() + 1);
		for (auto y = S.begin(); y != S.end(); ++y) {
			const auto it = upper_bound(S.begin(), y, *y - s);
			if (it != S.begin()) {
				const auto x = it - 1;
				ans = min(ans, (int)distance(x, y));
			}
		}
		return (ans == INT_MAX) ? 0 : ans;
	}
};
