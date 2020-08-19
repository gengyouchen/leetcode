template <class T, class F>
T lowestTrue(T low, T high, F cond) {
	while (low < high) {
		const T mid = low + (high - low) / 2;
		if (cond(mid))
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

class Solution {
public:
	/* time: O(log(min(m,n))), space: O(1), where m = |nums1|, n = |nums2| */
	static double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);

		const int m = nums1.size(), n = nums2.size(), k = (m + n) / 2;
		/*
		 * We need to pick top-k smallest elements from (nums1 + nums2).
		 * For those k elements, how many of them are in nums1?
		 * Do binary search for the answer as k1
		 */
		auto cond = [&](int k1) {
			const int k2 = k - k1;
			return nums1[k1] >= nums2[k2 - 1];
		};
		const int k1 = lowestTrue(0, m, cond), k2 = k - k1;
		/*
		 * Notice that we don't need to double check nums2[k2] >= nums1[k1 - 1] because:
		 * k1 is already the lowest value such that nums1[k1] >= nums2[k2 - 1],
		 * which means nums1[k1 - 1] < nums2[k2 - 1] <= nums2[k2]
		 */

		const int R = (k1 == m) ? nums2[k2] : (k2 == n) ? nums1[k1] : min(nums1[k1], nums2[k2]);
		if ((m + n) % 2)
			return R;
		const int L = (k1 == 0) ? nums2[k2 - 1] : (k2 == 0) ? nums1[k1 - 1] : max(nums1[k1 - 1], nums2[k2 - 1]);
		return (double)(L + R) / 2;
	}
};
