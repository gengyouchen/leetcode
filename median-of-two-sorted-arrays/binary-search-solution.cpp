class Solution {
private:
	template <class I, class F>
	I findFirstTrue(I first, I last, F cond) {
		while (first != last) {
			I mid = first + (last - first) / 2;
			if (cond(mid))
				last = mid;
			else
				first = mid + 1;
		}
		return first;
	}
public:
	/* time: O(log(min(m,n))), space: O(1) */
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);

		int m = nums1.size(), n = nums2.size(), k = (m + n + 1) / 2;
		/*
		 * Split into k smaller elements, and (m + n - k) larger elements
		 * For those k smaller elements, how many are in array nums1?
		 * Do binary search for this answer as k1
		 */
		int k1 = findFirstTrue(0, m, [&](int k1) {
				int k2 = k - k1;
				return (k2 == 0) || (nums2[k2 - 1] <= nums1[k1]);
				});
		int k2 = k - k1;

		int left = (k1 == 0) ? nums2[k2 - 1] : (k2 == 0) ? nums1[k1 - 1] : max(nums1[k1 - 1], nums2[k2 - 1]);
		int right = (k1 == m) ? nums2[k2] : (k2 == n) ? nums1[k1] : min(nums1[k1], nums2[k2]);
		return ((m + n) % 2) ? left : (double)(left + right) / 2;
	}
};
