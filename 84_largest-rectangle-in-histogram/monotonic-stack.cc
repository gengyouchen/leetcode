class Solution {
 public:
  /*
   * time: O(n), space: O(n), where n = # of bars
   *
   * See also:
   *     85. Maximal Rectangle
   *   1504. Count Submatrices With All Ones
   */
  int largestRectangleArea(const vector<int>& heights) {
    int n = heights.size(), ans = 0;
    stack<int> mono;
    for (int i = 0; i <= n; ++i) {
      int curr = (i < n) ? heights[i] : 0; /* appended a zero bar */
      while (!mono.empty() && heights[mono.top()] >= curr) {
        int j = mono.top();
        mono.pop();
        int k = mono.empty() ? -1 : mono.top();
        /*
         * The area of the largest rectangle using bar j as its height is:
         *   A = heights[j] * (i - k - 1), where k < j < i,
         *   and bar k is the last bar which is shorter than bar j,
         *   and bar i is the first bar which is shorter than bar j.
         *
         * Notice that: for our monotonic stack approach,
         *   our bar i is the first bar which is not taller than bar j.
         *
         * If heights[j] == heights[i], our A is not correctly computed.
         *
         * But this won't affect ans because in the future iterations,
         *   once heights[j] > heights[i], we can correctly get that A.
         */
        int A = heights[j] * (i - k - 1);
        ans = max(ans, A);
      }
      mono.push(i);
    }
    return ans;
  }
};
