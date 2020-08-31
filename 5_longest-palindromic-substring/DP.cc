class Solution {
 public:
  /*
   * Dynamic Programming
   * time: O(n^2), space: O(n), where n = s.size()
   *
   * See also:
   *   647. Palindromic Substrings
   */
  string longestPalindrome(const string& s) {
    const int n = s.size();
    int max_len = 0, ans = 0;

    vector<char> dp[2];
    dp[0].resize(n);
    dp[1].resize(n);
    auto DP = [&](int i, int j) -> char& { return dp[i % 2][j]; };

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        const int len = j - i + 1;
        if (len == 1)
          DP(i, j) = true;
        else if (len == 2)
          DP(i, j) = (s[i] == s[j]);
        else
          DP(i, j) = DP(i + 1, j - 1) && (s[i] == s[j]);

        if (DP(i, j) && len > max_len) {
          max_len = len;
          ans = i;
        }
      }
    }
    return s.substr(ans, max_len);
  }
};
