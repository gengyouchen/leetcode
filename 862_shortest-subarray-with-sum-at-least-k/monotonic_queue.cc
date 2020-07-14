class Solution {
 public:
  /*
   * time: O(n), space: O(n), where n = nums.size()
   *
   * Notice that if all input numbers >= 0, it becomes a easier problem:
   *   209. Minimum Size Subarray Sum
   */
  int shortestSubarray(const vector<int>& A, int K) {
    int n = A.size(), ans = INT_MAX;
    vector<int> prefix(n + 1);
    partial_sum(A.begin(), A.end(), prefix.begin() + 1);

    deque<int> L;
    for (int R = 0; R <= n; ++R) {
      /*
       * Once a certain L can be paired with our current R,
       *   we don't need to consider pairing this L for any future R' > R
       *   because they won't produce any shorter subarray.
       */
      while (!L.empty() && prefix[R] - prefix[L.front()] >= K) {
        ans = min(ans, R - L.front());
        L.pop_front();
      }

      /*
       * All candidates of L should be monotonic increasing.
       *
       * Proof by contradiction: if prefix[L] >= prefix[L'], where L < L' < R,
       *   L cannot become the final ans (R - L) because we can always replace
       *   L with L' to get a shorter subarray with a larger or equal sum.
       */
      while (!L.empty() && prefix[L.back()] >= prefix[R]) L.pop_back();
      L.push_back(R);
    }

    if (ans == INT_MAX) return -1;
    return ans;
  }
};
