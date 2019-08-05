class Solution {
public:
	/*
	 * time: O(m + n), space: O(n) auxiliary (i.e. does not count output itself),
	 * where m = len(nums1), n = len(nums2)
	 */
	static vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2) {
		const int m = nums1.size(), n = nums2.size();
		unordered_map<int, int> nextGreater;
		stack<int> mono;
		for (int i = 0; i < n; ++i) {
			while (!mono.empty() && mono.top() < nums2[i])
				nextGreater[mono.top()] = nums2[i], mono.pop();
			mono.push(nums2[i]);
		}

		vector<int> ans(m, -1);
		for (int i = 0; i < m; ++i) {
			const auto it = nextGreater.find(nums1[i]);
			if (it != nextGreater.end())
				ans[i] = it->second;
		}
		return ans;
	}
};
