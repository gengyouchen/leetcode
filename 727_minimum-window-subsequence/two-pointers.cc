class Solution {
 public:
  /*
   * time: O(n * m), extra space: O(1) (i.e. does not count output size)
   *   where n = S.size(), m = T.size()
   *
   * Complexity Analysis:
   * If we only call forward_match started from each L,
   *   which is the brute-force approach, the total time complexity is O(n^2).
   *
   * By calling backward_match after each forward_match, we can guarantee:
   * If in a certain forward_match call, we have compared S[i] with T[x],
   *   in future forward_match calls, we NEVER compare S[i] with T[x] again.
   *   (i.e. S[i] will be compared with T[y], where y > x)
   *
   * Therefore, S[i] is only compared with T at most 2*m times, NOT n times,
   *   so the total time complexity is just O(n * m).
   */
  string minWindow(const string& S, const string& T) {
    const int n = S.size(), m = T.size();
    auto forward_match = [&](int L) {
      int matched_len = 0;
      for (int R = L; R < n; ++R) {
        if (S[R] == T[matched_len]) ++matched_len;
        if (matched_len == m) return R;
      }
      return -1;
    };
    auto backward_match = [&](int R) {
      int matched_len = 0;
      for (int L = R; L >= 0; --L) {
        if (S[L] == T[m - 1 - matched_len]) ++matched_len;
        if (matched_len == m) return L;
      }
      return -1;
    };

    int ans_pos = -1, ans_len = INT_MAX;
    for (int L = 0; L < n; ++L) {
      const int R = forward_match(L);
      if (R == -1) break;

      L = backward_match(R);
      /* L is the rightmost L such that forward_match(L) is still the same R */

      const int len = R - L + 1;
      if (len < ans_len) ans_len = len, ans_pos = L;
    }
    if (ans_pos == -1) return "";

    return S.substr(ans_pos, ans_len);
  }
};
