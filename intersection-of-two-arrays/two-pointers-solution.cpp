class Solution {
public:
	/* time: O(m*log(m) + n*log(n)), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		const int m = nums1.size(), n = nums2.size();
		make_heap(nums1.begin(), nums1.end()), sort_heap(nums1.begin(), nums1.end());
		make_heap(nums2.begin(), nums2.end()), sort_heap(nums2.begin(), nums2.end());

		vector<int> ans;
		int i = 0, j = 0;
		while (i < m && j < n) {
			if (i < m - 1 && nums1[i] == nums1[i + 1] || nums1[i] < nums2[j])
				++i;
			else if (j < n - 1 && nums2[j] == nums2[j + 1] || nums1[i] > nums2[j])
				++j;
			else
				ans.push_back(nums1[i]), ++i, ++j;
		}
		return ans;
	}
};
