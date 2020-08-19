class Solution {
 public:
  /*
   * time: O(log(min(m, n))), extra space: O(1),
   * where m = nums1.size(), n = nums2.size();
   */
  double findMedianSortedArrays(const vector<int>& nums1,
                                const vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size(), k = (m + n) / 2;
    if (m > n) return findMedianSortedArrays(nums2, nums1);

    /*
     * Our goal is to pick top-k smallest numbers from (nums1 + nums2).
     *   k1 = how many of those k numbers are in nums1?
     *   k2 = k - k1 = how many of those k numbers are in nums2?
     *
     * We can do binary search for k1:
     *   (1) unless k1 == 0,
     *       k1 should be smaller enough such that nums1[k1 - 1] <= nums2[k2].
     *   (2) unless k1 == k,
     *       k1 should be larger enough such that nums2[k2 - 1] <= nums1[k1].
     *
     * We can say that (1) defined the upper bound of k1,
     *           while (2) defined the lower bound of k1.
     *
     * Since k1 exists, use either (1) or (2) is okay to find a valid k1.
     */
    auto lowest_true = [&](const auto& cond, int L, int R) -> int {
      while (L < R) {
        int mid = L + (R - L) / 2;
        if (cond(mid))
          R = mid;
        else
          L = mid + 1;
      }
      return L;
    };
    auto cond = [&](int k1) -> bool {
      int k2 = k - k1;
      return nums2[k2 - 1] <= nums1[k1];
    };
    int k1 = lowest_true(cond, 0, m); /* if 0 ~ m-1 are all false, we get m */
    int k2 = k - k1;

    int kth = (k1 == m) ? nums2[k2]
                        : (k2 == n) ? nums1[k1] : min(nums1[k1], nums2[k2]);
    if ((m + n) % 2) return kth;

    int kth_prev = (k1 == 0) ? nums2[k2 - 1]
                             : (k2 == 0) ? nums1[k1 - 1]
                                         : max(nums1[k1 - 1], nums2[k2 - 1]);
    return (kth + kth_prev) / 2.0;
  }
};
