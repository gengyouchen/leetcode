class Solution {
 public:
  /*
   * time: O(n * C(n)), where C is the Catalan number,
   *   extra space: O(n) (i.e. does not count output size)
   */
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string buf(n * 2, ' ');

    auto backtrack = [&](const auto& backtrack, int n_L, int n_R) -> void {
      int pos = n_L + n_R;
      if (pos == buf.size()) {
        ans.push_back(buf);
      } else {
        if (n_L < n) {
          buf[pos] = '(';
          backtrack(backtrack, n_L + 1, n_R);
        }
        if (n_R < n_L) {
          buf[pos] = ')';
          backtrack(backtrack, n_L, n_R + 1);
        }
      }
    };
    backtrack(backtrack, 0, 0);
    return ans;
  }
};
