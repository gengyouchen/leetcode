class Solution {
 public:
  /*
   * time: O(m * n), space: O(n), where m = # of rows, n = # of columns
   *
   * See also:
   *     84. Largest Rectangle in Histogram
   *   1504. Count Submatrices With All Ones
   */
  int maximalRectangle(const vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), ans = 0;
    vector<int> h(n), last_zero_before(n), first_zero_after(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1')
          ++h[j];
        else
          h[j] = 0;
      }

      int last_zero = -1;
      for (int j = 0; j < n; ++j) {
        if (h[j] > 1)
          last_zero_before[j] = max(last_zero_before[j], last_zero);
        else if (h[j] == 1)
          last_zero_before[j] = last_zero;
        else
          last_zero = j;
      }

      int first_zero = n;
      for (int j = n - 1; j >= 0; --j) {
        if (h[j] > 1)
          first_zero_after[j] = min(first_zero_after[j], first_zero);
        else if (h[j] == 1)
          first_zero_after[j] = first_zero;
        else
          first_zero = j;
      }

      for (int j = 0; j < n; ++j) {
        if (h[j] > 0) {
          int A = h[j] * (first_zero_after[j] - last_zero_before[j] - 1);
          ans = max(ans, A);
        }
      }
    }
    return ans;
  }
};
