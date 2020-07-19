class Solution {
 public:
  /*
   * time: O(n), where n = s.size(),
   *   extra space: O(1) (i.e. does not count output size)
   */
  vector<string> maxNumOfSubstrings(const string& s) {
    int leftmost[26], rightmost[26];
    fill_n(leftmost, 26, INT_MAX);
    fill_n(rightmost, 26, INT_MIN);

    int n = s.size();
    for (int i = 0; i < n; ++i) {
      int u = s[i] - 'a';
      leftmost[u] = min(leftmost[u], i);
      rightmost[u] = max(rightmost[u], i);
    }

    auto getShortestValid = [&](int L) {
      if (L < 0 || L >= n) return -1;
      int R = L;
      for (int i = L; i <= R; ++i) {
        int u = s[i] - 'a';
        if (leftmost[u] < L) return -1;
        R = max(R, rightmost[u]);
      }
      return R;
    };

    vector<pair<int, int>> valid_ranges;
    for (int u = 0; u < 26; ++u) {
      int L = leftmost[u], R = getShortestValid(L);
      if (R != -1) valid_ranges.emplace_back(L, R);
    }

    /*
     * It's impossible for any two valid substrings X and Y to overlap
     *   unless one is inside another.
     *
     * To pick max # of valid substrings, if Y is inside X, pick Y instead of X
     *   such that we are allowed to pick other valid substrings insides X.
     */
    vector<pair<int, int>> output_ranges;
    sort(valid_ranges.begin(), valid_ranges.end());
    for (const auto& range : valid_ranges) {
      if (!output_ranges.empty() && output_ranges.back().second > range.first)
        output_ranges.back() = range;
      else
        output_ranges.push_back(range);
    }

    vector<string> ans;
    for (const auto& range : output_ranges)
      ans.emplace_back(s, range.first, range.second - range.first + 1);
    return ans;
  }
};
