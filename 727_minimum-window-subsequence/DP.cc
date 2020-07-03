class Solution {
 public:
  /*
   * time: O(n * m), extra space: O(m) (i.e. does not count output size),
   *   where n = S.size(), m = T.size()
   */
  string minWindow(const string& S, const string& T) {
    const int n = S.size(), m = T.size();
    vector<vector<int>> dp(2, vector<int>(m, -1));
    auto DP = [&](int i, int j) -> int& { return dp[i % 2][j]; };

    int ans_pos = -1, ans_len = INT_MAX;
    for (int L = n - 1; L >= 0; --L) {
      for (int pos = m - 1; pos >= 0; --pos) {
        if (S[L] != T[pos])
          DP(L, pos) = DP(L + 1, pos);
        else if (pos == m - 1)
          DP(L, pos) = L;
        else
          DP(L, pos) = DP(L + 1, pos + 1);
      }

      if (DP(L, 0) != -1) {
        const int len = DP(L, 0) - L + 1;
        if (len <= ans_len) ans_len = len, ans_pos = L;
      }
    }
    if (ans_pos == -1) return "";

    return S.substr(ans_pos, ans_len);
  }
};
