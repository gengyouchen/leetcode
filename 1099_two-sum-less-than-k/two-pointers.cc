class Solution {
 public:
  /* time: O(n*log(n)), extra space: O(1) */
  int twoSumLessThanK(vector<int>& A, int K) {
    const int n = A.size();
    make_heap(A.begin(), A.end());
    sort_heap(A.begin(), A.end());

    int L = 0, R = n - 1, ans = -1;
    while (L < R) {
      const int s = A[L] + A[R];
      if (s < K) {
        ans = max(ans, s);
        /*
         * For any i between L+1 ~ R, A[L] + A[i] <= s,
         * so L can be excluded if final answer is not s.
         */
        ++L;
      } else {
        /*
         * For any i between L ~ R-1, A[i] + A[R] >= K,
         * so R can be excluded.
         */
        --R;
      }
    }
    return ans;
  }
};
