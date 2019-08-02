class Solution {
public:
	/* time: O(m+n), space: O(min(m,n)) auxiliary (i.e. does not count input & output itself) */
	static vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			swap(nums1, nums2);

		unordered_multiset<int> s(nums1.begin(), nums1.end());
		vector<int> ans;
		for (int num : nums2) {
			const auto it = s.find(num);
			if (it != s.end())
				ans.push_back(num), s.erase(it);
		}
		return ans;
	}
};
