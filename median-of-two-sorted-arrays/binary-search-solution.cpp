class Solution {
private:
	template <class T, class F>
	T findPassMark(T low, T high, F canPass) {
		while (low < high) {
			T mid = low + (high - low) / 2;
			if (canPass(mid))
				high = mid;
			else
				low = mid + 1;
		}
		return low;
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
		 * Do binary search for this answer as k1
		 */
		const int k1 = findPassMark(0, m, [&](int i) {
			const int k1 = i, k2 = k - i;
			return (k2 == 0) || (nums2[k2 - 1] <= nums1[k1]);
		});
		const int k2 = k - k1;

		const int L = (k1 == 0) ? nums2[k2 - 1] : (
				(k2 == 0) ? nums1[k1 - 1] : max(nums1[k1 - 1], nums2[k2 - 1]));
		const int R = (k1 == m) ? nums2[k2] : (
				(k2 == n) ? nums1[k1] : min(nums1[k1], nums2[k2]));
		return ((m + n) % 2) ? L : (double)(L + R) / 2;
	}
};
