class Solution {
 public:
  /*
   * time: O(n + L), space: O(n),
   *   where n = S.size(), L = total # of chars in words
   */
  int numMatchingSubseq(const string& S, const vector<string>& words) {
    const int n = S.size();
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

    int ans = 0;
    for (const auto& word : words) {
      int matched_len = 0, pos = 0;
      for (char c : word) {
        if (pos >= n) break;
        pos = next_pos[pos][c - 'a'];
        if (pos == -1) break;

        ++matched_len;
        ++pos;
      }

      if (matched_len == word.size()) ++ans;
    }
    return ans;
  }
};
