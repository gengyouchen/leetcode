class Solution {
 public:
  /*
   * time: O(2^n * n), extra space: O(n), where n = # of candidates
   *
   * See also:
   *    39. Combination Sum
   *   216. Combination Sum III
   *   377. Combination Sum IV
   */
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n = candidates.size();
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> buf;
    auto backtrack = [&](const auto& backtrack, int start, int sum) -> void {
      if (sum == target) ans.push_back(buf);
      if (sum < target) {
        for (int i = start; i < n; ++i) {
          if (i > start && candidates[i - 1] == candidates[i]) continue;
          buf.push_back(candidates[i]);
          backtrack(backtrack, i + 1, sum + candidates[i]);
          buf.pop_back();
        }
      }
    };
    backtrack(backtrack, 0, 0);
    return ans;
  }
};
