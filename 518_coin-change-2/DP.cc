class Solution {
 public:
  /*
   * time: O(n * amount), space: O(amount), where n = coins.size()
   *
   * See also:
   *   322. Coin Change
   *   377. Combination Sum IV
   */
  int change(int amount, const vector<int>& coins) {
    /*
     * dp[i][j] = # of combinations to make up amount j using coin type 0 ~ i
     * -> dp[i][j] = sum { dp[i - 1][j - coins[i] * k] for k >= 0 }
     * -> dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]
     */
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int coin : coins) {
      for (int sum = 0; sum <= amount; ++sum)
        if (sum - coin >= 0) dp[sum] += dp[sum - coin];
    }
    return dp[amount];
  }
};
