class Solution {
 public:
  /*
   * time: O(2^n * n), extra space: O(n), where n = # of candidates
   *
   * See also:
   *    40. Combination Sum II
   *   216. Combination Sum III
   *   377. Combination Sum IV
   */
  vector<vector<int>> combinationSum(const vector<int>& candidates,
                                     int target) {
    int n = candidates.size();

    vector<vector<int>> ans;
    vector<int> buf;
    auto backtrack = [&](const auto& backtrack, int start, int sum) -> void {
      if (sum == target) ans.push_back(buf);
      if (sum < target) {
        for (int i = start; i < n; ++i) {
          buf.push_back(candidates[i]);
          backtrack(backtrack, i, sum + candidates[i]);
          buf.pop_back();
        }
      }
    };
    backtrack(backtrack, 0, 0);
    return ans;
  }
};
