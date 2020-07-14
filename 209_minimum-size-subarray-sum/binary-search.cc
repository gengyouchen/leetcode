class Solution {
 public:
  /*
   * time: O(n * log(n)), space: O(n), where n = nums.size()
   *
   * This binary search approach only works if all input numbers >= 0.
   * If we allow some input numbers < 0, it becomes a harder problem:
   *   862. Shortest Subarray with Sum at Least K
   */
  int minSubArrayLen(int s, const vector<int>& nums) {
    int n = nums.size(), ans = INT_MAX;
    vector<int> prefix(n + 1);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    for (int R = 0; R <= n; ++R) {
      /* For each R, find the largest L such that prefix[R] - prefix[L] >= s */
      auto it = upper_bound(prefix.begin(), prefix.begin() + R, prefix[R] - s);
      if (it != prefix.begin()) {
        int L = distance(prefix.begin(), prev(it));
        ans = min(ans, R - L);
      }
    }

    if (ans == INT_MAX) ans = 0;
    return ans;
  }
};
