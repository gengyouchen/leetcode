class Solution {
 public:
  /*
   * time: O(n * 2^n), extra space: O(n) (i.e. does not count output size),
   *   where n = s.size()
   *
   * See also:
   *     32. Longest Valid Parentheses
   *    921. Minimum Add to Make Parentheses Valid
   *   1249. Minimum Remove to Make Valid Parentheses
   */
  vector<string> removeInvalidParentheses(const string& s) {
    int n = s.size();
    auto quota = minRemoveToMakeValid(s);

    vector<string> ans;
    vector<int> removed_L, removed_R;

    auto backtrack = [&](const auto& backtrack, int pos, int n_opened) {
      if (pos == n) {
        if (n_opened > 0) return;
        string buf;
        int j = 0, k = 0;
        for (int i = 0; i < n; ++i) {
          if (j < removed_L.size() && i == removed_L[j])
            ++j;
          else if (k < removed_R.size() && i == removed_R[k])
            ++k;
          else
            buf += s[i];
        }
        ans.push_back(buf);
        return;
      }

      switch (s[pos]) {
        case '(':
          /* try to remove '(' */
          if (removed_R.size() == quota.second &&
              removed_L.size() < quota.first) {
            if (pos == 0 || s[pos - 1] != '(' ||
                (!removed_L.empty() && removed_L.back() == pos - 1)) {
              removed_L.push_back(pos);
              backtrack(backtrack, pos + 1, n_opened);
              removed_L.pop_back();
            }
          }

          /* try to preserve '(' */
          backtrack(backtrack, pos + 1, n_opened + 1);
          break;

        case ')':
          /* try to remove ')' */
          if (removed_R.size() < quota.second) {
            if (pos == 0 || s[pos - 1] != ')' ||
                (!removed_R.empty() && removed_R.back() == pos - 1)) {
              removed_R.push_back(pos);
              backtrack(backtrack, pos + 1, n_opened);
              removed_R.pop_back();
            }
          }

          /* try to preserve ')' */
          if (n_opened > 0) backtrack(backtrack, pos + 1, n_opened - 1);
          break;

        default:
          backtrack(backtrack, pos + 1, n_opened);
          break;
      }
    };
    backtrack(backtrack, 0, 0);
    return ans;
  }

 private:
  /* Reused the solution from 1249. Minimum Remove to Make Valid Parentheses */
  pair<int, int> minRemoveToMakeValid(const string& s) {
    int n_removed_L = 0, n_removed_R = 0;

    /*
     * A prefix of a parentheses string could be:
     *   1. balanced such as "(()())",
     *   2. opened such as "(()(",
     *   3. invalid such as "(()()))".
     *
     * If we want ans to be a balanced parentheses string,
     *   every prefix of ans must be balanced or opened.
     */
    int n_opened = 0;
    for (char c : s) {
      switch (c) {
        case '(':
          ++n_opened;
          break;

        case ')':
          if (n_opened > 0)
            --n_opened;
          else
            ++n_removed_R;
          break;
      }
    }

    /*
     * As long as ans is still an opened parentheses string,
     *   removing the rightmost '(' won't make any prefix of ans invalid.
     */
    if (n_opened > 0) n_removed_L += n_opened;

    return {n_removed_L, n_removed_R};
  }
};
