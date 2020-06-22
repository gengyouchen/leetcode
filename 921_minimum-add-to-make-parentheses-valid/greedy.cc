class Solution {
 public:
  /* time: O(n), extra space: O(1) */
  int minAddToMakeValid(const string& S) {
    int ans = 0, n_opened = 0;
    for (char c : S) {
      switch (c) {
        case '(':
          ++n_opened;
          break;

        case ')':
          if (n_opened > 0)
            --n_opened;
          else
            ++ans; /* add '(' */
          break;
      }
    }
    if (n_opened > 0) ans += n_opened; /* add ')' */
    return ans;
  }
};
