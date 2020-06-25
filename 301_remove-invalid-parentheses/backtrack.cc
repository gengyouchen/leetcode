class Solution {
 public:
  /*
   * time: O(2^n), extra space: O(n) (i.e. does not count output size)
   *
   * See also:
   *    921. Minimum Add to Make Parentheses Valid
   *.  1249. Minimum Remove to Make Valid Parentheses
   */
  vector<string> removeInvalidParentheses(const string& s) {
    const int n = s.size();
    auto quota = minRemoveToMakeValid(s);

    vector<string> ans;
    vector<int> removed_l, removed_r;

    using F = function<void(int, int)>;
    F backtrack = [&](int pos, int n_opened) {
      if (pos == n) {
        if (n_opened > 0) return;
        string buf;
        int j = 0, k = 0;
        for (int i = 0; i < n; ++i) {
          if (j < removed_l.size() && i == removed_l[j])
            ++j;
          else if (k < removed_r.size() && i == removed_r[k])
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
          if (removed_r.size() == quota.second &&
              removed_l.size() < quota.first) {
            if (pos == 0 || s[pos - 1] != '(' ||
                (!removed_l.empty() && removed_l.back() == pos - 1)) {
              removed_l.push_back(pos);
              backtrack(pos + 1, n_opened);
              removed_l.pop_back();
            }
          }

          /* try to preserve '(' */
          backtrack(pos + 1, n_opened + 1);
          break;

        case ')':
          /* try to remove ')' */
          if (removed_r.size() < quota.second) {
            if (pos == 0 || s[pos - 1] != ')' ||
                (!removed_r.empty() && removed_r.back() == pos - 1)) {
              removed_r.push_back(pos);
              backtrack(pos + 1, n_opened);
              removed_r.pop_back();
            }
          }

          /* try to preserve ')' */
          if (n_opened > 0) backtrack(pos + 1, n_opened - 1);
          break;

        default:
          backtrack(pos + 1, n_opened);
          break;
      }
    };
    backtrack(0, 0);
    return ans;
  }

 private:
  /*
   * Reused the solution from 1249. Minimum Remove to Make Valid Parentheses
   */
  pair<int, int> minRemoveToMakeValid(const string& s) {
    int n_removed_l = 0, n_removed_r = 0;

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
            ++n_removed_r;
          break;
      }
    }

    /*
     * As long as ans is still an opened parentheses string,
     *   removing the rightmost '(' won't make any prefix of ans invalid.
     */
    if (n_opened > 0) n_removed_l += n_opened;

    return {n_removed_l, n_removed_r};
  }
};
