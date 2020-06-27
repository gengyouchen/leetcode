class Solution {
 public:
  /* time: O(n * m), space: O(n), where n = S.size(), m = T.size() */
  string minWindow(const string& S, const string& T) {
    const int n = S.size(), m = T.size();
    vector<array<int, 26>> next_pos(n);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < 26; ++j) {
        if (S[i] == 'a' + j)
          next_pos[i][j] = i;
        else if (i == n - 1)
          next_pos[i][j] = -1;
        else
          next_pos[i][j] = next_pos[i + 1][j];
      }
    }

    int ans_pos = -1, ans_len = INT_MAX;
    for (int L = 0; L < n; ++L) {
      int R = L;
      for (int i = 0; i < m; ++i) {
        R = next_pos[R][T[i] - 'a'];
        if (R == -1) break;

        if (i == m - 1) {
          const int len = R - L + 1;
          if (len < ans_len) ans_len = len, ans_pos = L;
        }

        if (++R >= n) break;
      }
    }
    if (ans_pos == -1) return "";

    return S.substr(ans_pos, ans_len);
  }
};
