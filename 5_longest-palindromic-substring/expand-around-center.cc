class Solution {
 public:
  /*
   * Expand Around Center
   * time: O(n^2), space: O(1), where n = s.size()
   *
   * See also:
   *   647. Palindromic Substrings
   */
  string longestPalindrome(const string& s) {
    /*
     * A n-chars string has 2n+1 center points for palindromic substrings.
     * (e.g. a input string "cbbd" becomes "#c#b#b#d#")
     *
     * For each center point i,
     * expand its radius if it can still form a palindromic substring.
     * (e.g. for i = 4 in "#c#b#b#d#", its radius is 3, which is "#b#b#")
     */
    const int n = s.size(), n_centers = n * 2 + 1;
    auto expand = [&](int center) {
      int radius = 0;
      while (true) {
        const int left_bound = center - radius;
        if (left_bound < 0) break;

        const int right_bound = center + radius;
        if (right_bound >= n_centers) break;

        if (left_bound % 2 /* no need to compare '#' */ &&
            s[left_bound / 2] != s[right_bound / 2])
          break;
        ++radius;
      }
      return radius;
    };

    /* Build substring using the center point k whose radius is maximum */
    int k = 0, max_radius = 0;
    for (int i = 0; i < n_centers; ++i) {
      const int radius = expand(i);
      if (radius > max_radius) {
        max_radius = radius;
        k = i;
      }
    }
    const int first = k - max_radius + 2;
    const int last = k + max_radius - 2;
    return s.substr(first / 2, last / 2 - first / 2 + 1);
  }
};
