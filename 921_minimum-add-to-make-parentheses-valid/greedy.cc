class Solution {
 public:
  /*
   * time: O(n), space: O(1)
   *
   * See also:
   *    301. Remove Invalid Parentheses
   *   1249. Minimum Remove to Make Valid Parentheses
   */
  int minAddToMakeValid(const string& S) {
    int ans = 0;

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
    for (char c : S) {
      switch (c) {
        case '(':
          ++n_opened;
          break;

        case ')':
          if (n_opened > 0)
            --n_opened;
          else
            ++ans; /* insert '(' before c */
          break;
      }
    }

    /*
     * As long as ans is still an opened parentheses string,
     *   appending ')' won't make any prefix of ans invalid.
     */
    if (n_opened > 0) ans += n_opened; /* append ')' */

    return ans;
  }
};
