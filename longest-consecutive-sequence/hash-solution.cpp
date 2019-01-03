class Solution {
public:
	/* time: O(n), space: O(n) */
	int longestConsecutive(const vector<int>& nums) {
		unordered_set<int> h;
		for (int num : nums)
			h.insert(num);
		int ans = 0;
		for (int num : nums) {
			if (!h.count(num - 1)) {
				int len = 1;
				while (h.count(++num))
					++len;
				ans = max(ans, len);
			}
		}
		return ans;
	}
};
