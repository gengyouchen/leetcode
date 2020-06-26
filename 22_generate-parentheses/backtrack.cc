class Solution {
 public:
  /*
   * time: O(n * C(n)), where C is the Catalan number
   * extra space: O(n) (i.e. does not count output size),
   */
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string buf(n * 2, ' ');

    using F = function<void(int, int)>;
    F backtrack = [&](int n_added_L, int n_added_R) {
      const int pos = n_added_L + n_added_R;
      if (pos == buf.size()) {
        ans.push_back(buf);
      } else {
        if (n_added_L < n) {
          buf[pos] = '(';
          backtrack(n_added_L + 1, n_added_R);
        }
        if (n_added_R < n_added_L) {
          buf[pos] = ')';
          backtrack(n_added_L, n_added_R + 1);
        }
      }
    };
    backtrack(0, 0);
    return ans;
  }
};
