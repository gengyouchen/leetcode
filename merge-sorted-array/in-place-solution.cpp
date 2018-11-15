class Solution {
public:
	/* time: O(m+n), space: O(1) auxiliary (i.e. does not count intput & output itself) */
	void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
		int out = m + n;
		while (m && n)
			if (nums1[m - 1] > nums2[n - 1])
				nums1[--out] = nums1[--m];
			else
				nums1[--out] = nums2[--n];
		while (n)
			nums1[--out] = nums2[--n];
	}
};
