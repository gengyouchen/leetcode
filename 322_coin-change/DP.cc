class Solution {
 public:
  /*
   * time: O(n * amount),  where n = coins.size()
   * space: O(min(amount, max(coins)))
   *
   * See also:
   *   377. Combination Sum IV
   *   518. Coin Change 2
   */
  int coinChange(const vector<int>& coins, int amount) {
    /*
     * dp[i] = min # of coins to make up amount i
     * -> dp[i] = 1 + min { dp[i - coins[k]] for all k }
     */
    int largest_coin = *max_element(coins.begin(), coins.end());
    int window_size = min(amount, largest_coin) + 1;
    vector<int> dp(window_size);
    auto DP = [&](size_t i) -> int& { return dp[i % window_size]; };
    DP(0) = 0;
    for (int sum = 1; sum <= amount; ++sum) {
      DP(sum) = INT_MAX;
      for (int coin : coins) {
        if (sum - coin >= 0) DP(sum) = min(DP(sum), DP(sum - coin));
      }
      if (DP(sum) != INT_MAX) ++DP(sum);
    }
    return DP(amount) == INT_MAX ? -1 : DP(amount);
  }
};
