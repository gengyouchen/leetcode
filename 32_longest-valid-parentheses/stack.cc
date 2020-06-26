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
     * For each R, we find the leftmost L such that s[L...R] is balanced,
     *   and use it to update the longest ans = max(ans, R - L + 1)
     * Naively doing this for every R will spend O(n^2) time.
     *
     * We can improve to O(n) time using a stack to track L of each opened.
     * When our R visit a ')', we found a balanced s[L.top() ... R].
     * Notice that L.top() is just the closer L for R such that its balanced.
     * To find the leftmost L for R such that its balanced,
     *   we should L.pop(), and now the leftmost L is the current L.top() + 1
     */
    stack<int> L;
    L.push(-1); /* add an implict '(' */
    const int n = s.size();
    for (int R = 0; R < n; ++R) {
      switch (s[R]) {
        case '(':
          L.push(R);
          break;

        case ')':
          L.pop();
          if (!L.empty())
            ans = max(ans, R - L.top()); /* leftmost L = L.top() + 1 */
          else
            L.push(R); /* update that implict '(' */
          break;
      }
    }
    return ans;
  }
};
