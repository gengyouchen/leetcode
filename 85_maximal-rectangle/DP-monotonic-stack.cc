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
    vector<int> h(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1')
          ++h[j];
        else
          h[j] = 0;
      }
      ans = max(ans, maximalRectangleInHistogram(h));
    }
    return ans;
  }

 private:
  /* Reused the solution from 84. Largest Rectangle in Histogram */
  int maximalRectangleInHistogram(const vector<int>& h) {
    int n = h.size(), ret = 0;
    stack<int> mono;
    for (int i = 0; i <= n; ++i) {
      int curr = (i < n) ? h[i] : 0;
      while (!mono.empty() && h[mono.top()] >= curr) {
        int x = mono.top();
        mono.pop();
        int L = mono.empty() ? -1 : mono.top(), R = i;
        ret = max(ret, h[x] * (R - L - 1));
      }
      mono.push(i);
    }
    return ret;
  }
};
