class Solution {
 public:
  /*
   * time: O(n), space: O(1), where n = nums.size()
   *
   * This two pointers approach only works if all input numbers >= 0.
   * If we allow some input numbers < 0, it becomes a harder problem:
   *   862. Shortest Subarray with Sum at Least K
   */
  int minSubArrayLen(int s, const vector<int>& nums) {
    int n = nums.size(), L = -1, sum = 0, ans = INT_MAX;
    for (int R = 0; R < n; ++R) {
      /*
       * Once a certain L can be paired with our current R,
       *   we don't need to consider pairing this L for any future R' > R
       *   because they won't produce any shorter subarray.
       */
      sum += nums[R];
      while (L < R && sum >= s) {
        ans = min(ans, R - L);
        sum -= nums[++L];
      }
    }

    if (ans == INT_MAX) return 0;
    return ans;
  }
};
