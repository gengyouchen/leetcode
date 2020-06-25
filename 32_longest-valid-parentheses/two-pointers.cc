class Solution {
 public:
  /*
   * time: O(n), space: O(1)
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
     *   and use it to update the longest ans = max(ans, R - L + 1)
     * Naively doing this for every L will spend O(n^2) time.
     *
     * To achieve O(n) time, notice that NOT every L need to be considered.
     * After we find the rightmost R from a given L such that it's balanced,
     *   restarting from any L' between L+1 ~ R will only get a shorter R' < R
     * Therefore, next time we can safely restart from L' = R+1
     */
    const int n = s.size();
    int n_opened = 0, L = 0;
    for (int R = 0; R < n; ++R) {
      switch (s[R]) {
        case '(':
          ++n_opened;
          break;

        case ')':
          if (n_opened > 0) {
            --n_opened;
            if (n_opened == 0) ans = max(ans, R - L + 1);
          } else {
            L = R + 1;
          }
          break;
      }
    }

    /*
     * For a certain L', if we cannot find R' such that s[L'...R'] is balanced,
     *   which means s[L'...n-1] is still opened,
     *   we can still efficiently find longest parentheses substring after L'
     *   by backward scanning from n-1 because:
     *
     * It is guaranteed that starting from any R between L'+1 ~ n-1,
     *   we can always find a L > L' such that s[L...R] is balanced.
     */
    if (n_opened > 0) {
      int n_opened = 0, R = n - 1;
      for (int L = n - 1; L >= 0; --L) {
        switch (s[L]) {
          case ')':
            ++n_opened;
            break;

          case '(':
            if (n_opened > 0) {
              --n_opened;
              if (n_opened == 0) ans = max(ans, R - L + 1);
            } else {
              R = L - 1;
            }
            break;
        }
      }
    }
    return ans;
  }
};
