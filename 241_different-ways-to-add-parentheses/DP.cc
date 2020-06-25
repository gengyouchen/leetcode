class Solution {
 public:
  /*
   * time: O(C(n)), space: O(C(n)), where C is the Catalan number
   *
   * Complexity Analysis:
   * For a subproblem with size k,
   *   # of results in this subproblem is C(k-1),
   *   and each result can be computed in O(1) using smaller subproblems.
   *
   * Total # of results in all subproblems is
   *   T = 1*C(n-1) + 2*C(n-2) + 3*C(n-3) + 4*C(n-4) + ... + n*C(0)
   *     < 3*C(n-1) + 3*C(n-2) + 6*C(n-3) + 15*C(n-4) + ... + 3*C(n-1)*C(0)
   *     = 3*C(n)
   */
  vector<int> diffWaysToCompute(const string& input) {
    vector<char> ops;
    vector<int> nums(1);
    for (char c : input) {
      if (isdigit(c)) {
        nums.back() *= 10;
        nums.back() += (c - '0');
      } else {
        ops.push_back(c);
        nums.push_back(0);
      }
    }

    const int n = nums.size();
    vector<vector<Result>> dp(n, vector<Result>(n));
    for (int L = n; L >= 0; --L) {
      for (int R = L; R < n; ++R) {
        if (L == R) {
          dp[L][R].push_back(nums[L]);
        } else {
          for (int mid = L; mid < R; ++mid)
            cartesian(dp[L][R], dp[L][mid], dp[mid + 1][R], ops[mid]);
        }
      }
    }
    return dp[0][n - 1];
  }

 private:
  using Result = vector<int>;
  void cartesian(Result& out, const Result& a, const Result& b, char op) {
    for (int num1 : a) {
      for (int num2 : b) {
        switch (op) {
          case '+':
            out.push_back(num1 + num2);
            break;

          case '-':
            out.push_back(num1 - num2);
            break;

          case '*':
            out.push_back(num1 * num2);
            break;
        }
      }
    }
  }
};
