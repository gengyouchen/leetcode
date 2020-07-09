class Solution {
 public:
  /*
   * time: O(m * n), space: O(n), where m = # of rows, n = # of columns
   *
   * See also:
   *   84. Largest Rectangle in Histogram
   *   85. Maximal Rectangle
   */
  int numSubmat(const vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(), ans = 0;
    vector<int> h(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j])
          ++h[j];
        else
          h[j] = 0;
      }
      ans += numSubmatInHistogram(h);
    }
    return ans;
  }

 private:
  /*
   * Modified the monotonic stack solution from
   *   84. Largest Rectangle in Histogram
   *
   * Let dp[i] = # of all-one submatrices ending at bar i
   * Then, dp[i] = h[i] * (i - j) + dp[j], where j < i,
   *   and bar j is the last bar which is shorter than bar i
   */
  int numSubmatInHistogram(const vector<int>& h) {
    int n = h.size(), sum = 0;
    vector<int> dp(n);
    stack<int> mono;

    for (int i = 0; i < n; ++i) {
      while (!mono.empty() && h[mono.top()] >= h[i]) mono.pop();

      if (mono.empty())
        dp[i] = h[i] * (i + 1);
      else
        dp[i] = h[i] * (i - mono.top()) + dp[mono.top()];
      sum += dp[i];

      mono.push(i);
    }
    return sum;
  }
};
