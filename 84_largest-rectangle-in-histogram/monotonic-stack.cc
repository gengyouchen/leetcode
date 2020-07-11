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
      int curr = (i < n) ? heights[i] : 0; /* appended a zero bar at the end */
      while (!mono.empty() && heights[mono.top()] >= curr) {
        int x = mono.top();
        mono.pop();
        int L = mono.empty() ? -1 : mono.top(), R = i;
        /*
         * The area of the largest rectangle using bar x as its height is A(x):
         *   A(x) = heights[x] * (R - L - 1),
         *     where L < x < R,
         *     bar L is the last bar which is shorter than bar x,
         *     bar R is the first bar which is shorter than bar x.
         *
         * Notice that in our monotonic stack approach,
         *   our bar R is the first bar which is not taller than bar x.
         *
         * We don't need to worry if heights[x] == heights[R],
         *   our computed A(x) will be smaller than the correct A(x)
         *   because this won't affect the final answer:
         *     If heights[x] == heights[R], the correct A(x) == A(R).
         *     The final answer will pick A(R) in future iterations.
         */
        int A = heights[x] * (R - L - 1);
        ans = max(ans, A);
      }
      mono.push(i);
    }
    return ans;
  }
};
