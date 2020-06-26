class Solution {
 public:
  /*
   * time: O(n), space: O(n)
   *
   * See also:
   *    32. Longest Valid Parentheses
   *   301. Remove Invalid Parentheses
   *   921. Minimum Add to Make Parentheses Valid
   */
  string minRemoveToMakeValid(const string& s) {
    string ans;

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
          ans += c;
          break;

        case ')':
          if (n_opened > 0) {
            --n_opened;
            ans += c;
          }
          break;

        default:
          ans += c;
          break;
      }
    }

    /*
     * As long as ans is still an opened parentheses string,
     *   removing the rightmost '(' won't make any prefix of ans invalid.
     */
    if (n_opened > 0) {
      for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        if (*it == '(') {
          *it = '#';
          --n_opened;

          if (n_opened == 0) break;
        }
      }

      auto last = remove(ans.begin(), ans.end(), '#');
      ans.erase(last, ans.end());
    }

    return ans;
  }
};
