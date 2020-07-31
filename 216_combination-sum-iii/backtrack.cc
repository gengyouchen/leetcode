class Solution {
 public:
  /*
   * time: O(C(9, k) * k), extra space: O(k)
   *
   * See also:
   *    39. Combination Sum
   *    40. Combination Sum II
   *   377. Combination Sum IV
   */
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> buf;
    auto backtrack = [&](const auto& backtrack, int start, int sum) -> void {
      if (sum == n && buf.size() == k) ans.push_back(buf);
      if (sum < n && buf.size() < k) {
        for (int num = start; num <= 9; ++num) {
          buf.push_back(num);
          backtrack(backtrack, num + 1, sum + num);
          buf.pop_back();
        }
      }
    };
    backtrack(backtrack, 1, 0);
    return ans;
  }
};
