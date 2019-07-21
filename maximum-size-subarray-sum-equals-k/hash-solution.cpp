class Solution {
public:
	/* time: O(n), space: O(n) */
	static int maxSubArrayLen(const vector<int>& nums, int k) {
		const int n = nums.size();
		int ans = 0, prefix = 0;
		unordered_map<int, int> prefix2index;

		prefix2index[0] = 0;
		for (int i = 1; i <= n; ++i) {
			prefix += nums[i - 1];
			if (prefix2index.count(prefix - k))
				ans = max(ans, i - prefix2index[prefix - k]);
			if (!prefix2index.count(prefix))
				prefix2index[prefix] = i;
		}
		return ans;
	}
};
