class Solution {
 public:
  /*
   * time: O(n), space: O(n)
   *
   * See also:
   *    301. Remove Invalid Parentheses
   *    921. Minimum Add to Make Parentheses Valid
   *   1249. Minimum Remove to Make Valid Parentheses
   */
  int longestValidParentheses(const string& s) {
    int ans = 0;

    /*
     * Given a parentheses string s[0...n-1], its substring s[L...R] could be:
     *   1. balanced such as "(()())",
     *   2. opened such as "(()(",
     *   3. invalid such as "(()()))".
     *
     * For each L, we find the rightmost R such that s[L...R] is balanced,
     *   and use its len = R - L + 1 to update the longest ans = max(ans, len)
     * Naively doing this for every L will spend O(n^2) time.
     *
     * We can improve to O(n) time using DP:
     * For L=i, compute its len = dp[i] using the dp[i+1] and dp[i+dp[i+1]+2]
     */
    const int n = s.size();
    vector<int> dp(n);
    auto S = [&](int i) { return (i < n) ? s[i] : '('; };
    auto DP = [&](int i) { return (i < n) ? dp[i] : 0; };
    for (int i = n - 1; i >= 0; --i) {
      switch (s[i]) {
        case '(':
          if (i == n - 1) {
            dp[i] = 0;
          } else {
            switch (s[i + 1]) {
              case '(':
                if (S(i + dp[i + 1] + 1) == ')')
                  dp[i] = 1 + dp[i + 1] + 1 + DP(i + dp[i + 1] + 2);
                else
                  dp[i] = 0;
                break;

              case ')':
                dp[i] = 2 + DP(i + 2);
                break;
            }
          }
          break;

        case ')':
          dp[i] = 0;
          break;
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
