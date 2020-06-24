class Solution {
 public:
  /* time: O(n), space: O(n) */
  string minRemoveToMakeValid(const string& s) {
    string ans;
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
