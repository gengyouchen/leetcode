class Solution {
private:
	template <class T, class F>
	T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
public:
	/* time: O(log(min(m,n))), space: O(1) */
	double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);

		const int m = nums1.size(), n = nums2.size(), k = (m + n + 1) / 2;
		/*
		 * Split into k smaller elements, and (m + n - k) larger elements
		 * For those k smaller elements, how many are in array nums1?
		 * Do binary search for the answer as k1
		 */
		const int k1 = lowestTrue(0, m, [&](int k1) { return nums2[(k - k1) - 1] <= nums1[k1]; });
		const int k2 = k - k1;

		const int L = k1 ? k2 ? max(nums1[k1 - 1], nums2[k2 - 1]) : nums1[k1 - 1] : nums2[k2 - 1];
		const int R = (k1 < m) ? (k2 < n) ? min(nums1[k1], nums2[k2]) : nums1[k1] : nums2[k2];
		return ((m + n) % 2) ? L : (double)(L + R) / 2;
	}
};
