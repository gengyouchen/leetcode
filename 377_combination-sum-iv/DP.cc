class Solution {
 public:
  /*
   * time: O(n * target), where n = nums.size()
   * space: O(min(target, max(nums)))
   *
   * This problem is actually the "Permutation" Sum
   *   because different sequences are counted as different combinations.
   * For the "Combination" Sum problem, please refer to 518. Coin Change 2
   *
   * See also:
   *   322. Coin Change
   *   518. Coin Change 2
   */
  int combinationSum4(const vector<int>& nums, int target) {
    if (nums.empty()) return target ? 0 : 1;
    int max_num = *max_element(nums.begin(), nums.end());
    int window_size = min(target, max_num) + 1;
    vector<uint64_t> dp(window_size);
    auto DP = [&](int i) -> uint64_t& { return dp[i % window_size]; };

    /*
     * dp[i] = # of permutations to add up to sum i
     * -> dp[i] = 1 + min { dp[i - nums[k]] for all k }
     */
    DP(0) = 1;
    for (int sum = 1; sum <= target; ++sum) {
      DP(sum) = 0;
      for (int num : nums)
        if (sum >= num) DP(sum) += DP(sum - num);
    }
    return DP(target);
  }
};
