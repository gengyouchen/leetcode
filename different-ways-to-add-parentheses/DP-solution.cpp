class Solution {
private:
	enum OP { ADD, SUB, MUL };
	typedef vector<int> Result;
	typedef vector<Result> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(Catalan(n)), space: O(Catalan(n)), where n = # of numbers */
	vector<int> diffWaysToCompute(const string& input) {
		vector<int> nums, ops;
		bool inNum = false;
		int num = 0;
		for (char c : input) {
			if (c != ' ') {
				if (isdigit(c)) {
					num = num * 10 + (c - '0'), inNum = true;
				} else {
					if (inNum)
						nums.push_back(num), num = 0, inNum = false;
					switch (c) {
					case '+':
						ops.push_back(ADD);
						break;
					case '-':
						ops.push_back(SUB);
						break;
					case '*':
						ops.push_back(MUL);
						break;
					}
				}
			}
		}
		if (inNum)
			nums.push_back(num), num = 0, inNum = false;

		const int n = nums.size();
		auto dp = V2D(n, V1D(n));

		auto generate = [&](int L, int R) {
			/*
			 * The time of a single generate(L, R) function call is O(Catalan(R - L))
			 * <Proof>
			 * If R == L:
			 *     len(dp[L][R]) = 1
			 * If R == L + 1:
			 *     len(dp[L][R]) = 1
			 * If R > L + 1:
			 *     len(dp[L][R]) = sum { len(dp[L][p]) * len(dp[p+1][R]) for all p in [L, R-1] }
			 *
			 * This is exactly the recursive relationship of the Catalan number:
			 *     Catalan(0) = 1
			 *     Catalan(1) = 1
			 *     Catalan(k) = sum { Catalan(i) * Catalan(k-1-i) for all i in [0, k-1] }
			 *
			 * Therefore, O(len(dp[L][R])) = O(Catalan(R - L))
			 */
			if (L == R) {
				dp[L][R].push_back(nums[L]);
				return;
			}

			for (int p = L; p < R; ++p) {
				for (auto a : dp[L][p]) {
					for (auto b : dp[p + 1][R]) {
						switch (ops[p]) {
						case ADD:
							dp[L][R].push_back(a + b);
							break;
						case SUB:
							dp[L][R].push_back(a - b);
							break;
						case MUL:
							dp[L][R].push_back(a * b);
							break;
						}
					}
				}
			}
		};

		/*
		 * The total time of all generate(L, R) function calls is O(Catalan(n))
		 * <Proof>
		 * T = 1*Catalan(n-1) + 2*Catalan(n-2) + 3*Catalan(n-3) + 4*Catalan(n-4) + 5*Catalan(n-5) + 6*Catalan(n-6)...
		 *      ^                ^                ^                ^                ^                ^
		 *      dp[0][n-1]       dp[0][n-2]       dp[0][n-3]       dp[0][n-4]       dp[0][n-5]       dp[0][n-6]
		 *                       dp[1][n-1]       dp[1][n-2]       dp[1][n-3]       dp[1][n-4]       dp[1][n-5]
		 *                                        dp[2][n-1]       dp[2][n-2]       dp[2][n-3]       dp[2][n-4]
		 *                                                         dp[3][n*1]       dp[3][n-2]       dp[3][n-3]
		 *                                                                          dp[4][n-1]       dp[4][n-2]
		 *                                                                                           dp[5][n-1]
		 *
		 * T <= 3*Catalan(n-1) + 3*Catalan(n-2) + 6*Catalan(n-3) + 15*Catalan(n-4) + 42*Catalan(n-5) + ...
		 *    = 3*Catalan(0)*Catalan(n-1) + 3*Catalan(1)*Catalan(n-2) + 3*Catalan(2)*Catalan(n-3) + ...
		 *    = 3*(Catalan(0)*Catalan(n-1) + Catalan(1)*Catalan(n-2) + Catalan(2)*Catalan(n-3) + ...)
		 *    = 3*Catalan(n)
		 */
		for (int L = n; L >= 0; --L) {
			for (int R = L; R < n; ++R)
				generate(L, R);
		}
		return dp[0][n - 1];
	}
};
