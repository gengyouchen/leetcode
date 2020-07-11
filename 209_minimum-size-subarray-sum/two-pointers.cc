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
    int n = nums.size(), R = 0, sum = 0, ans = INT_MAX;
    for (int L = 0; L < n; ++L) {
      while (sum < s && R < n) sum += nums[R++];
      if (sum >= s) ans = min(ans, R - L);
      sum -= nums[L];
    }
    if (ans == INT_MAX) return 0;
    return ans;
  }
};
