class Solution {
 public:
  /*
   * Manacher's algorithm
   * time: O(n), space: O(n), where n = s.size()
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
     * expand radius[i] if it can still form a palindromic substring.
     * (e.g. for i = 4 in "#c#b#b#d#", the radius[i] is 3, which is "#b#b#")
     */
    const int n = s.size(), n_centers = n * 2 + 1;
    vector<int> radius(n_centers);
    auto expand = [&](int center) {
      while (true) {
        const int left_bound = center - radius[center];
        if (left_bound < 0) break;

        const int right_bound = center + radius[center];
        if (right_bound >= n_centers) break;

        if (left_bound % 2 /* no need to compare '#' */ &&
            s[left_bound / 2] != s[right_bound / 2])
          break;
        ++radius[center];
      }
    };

    /*
     * The trick in Manacher algorithm is that:
     * For each center point i, we do NOT have to expand radius[i] from zero.
     *
     * Let a center point c < i, whose right bound (c + radius[c]) is maximum.
     * We can mirrow i to j based on c, and use radius[j] to compute radius[i].
     *
     * The right bound (c + radius[c]) will be increased at most O(n) times,
     * so the total time complexity is just O(n).
     */
    int c = 0;
    for (int i = 0; i < n_centers; ++i) {
      const int right_bound = c + radius[c];
      if (i == right_bound) {
        expand(i);
        c = i;
      } else {
        const int j = c - (i - c);
        if (i + radius[j] < right_bound) {
          radius[i] = radius[j];
        } else if (i + radius[j] > right_bound) {
          radius[i] = right_bound - i;
        } else {
          radius[i] = radius[j];
          expand(i);
          c = i;
        }
      }
    }

    /* Build substring using the center point k whose radius is maximum */
    const int k = max_element(radius.begin(), radius.end()) - radius.begin();
    const int first = k - radius[k] + 2;
    const int last = k + radius[k] - 2;
    return s.substr(first / 2, last / 2 - first / 2 + 1);
  }
};
