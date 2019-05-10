class Solution {
private:
	typedef unordered_set<string> S;
	static S single(const string& s) {
		S out;
		out.insert(s);
		return out;
	}
	static S startsWith(const S& x, char c) {
		S out;
		for (const auto& a : x)
			out.insert(c + a);
		return out;
	}
	static S endsWith(const S& x, char c) {
		S out;
		for (const auto& a : x)
			out.insert(a + c);
		return out;
	}
	static void crossJoin(S& out, const S& x, const S& y) {
		for (const auto& a : x) {
			for (const auto& b : y)
				out.insert('(' + a + ')' + b);
		}
	}
	typedef function<S&(int, int)> F;
public:
	/*
	 * time: O(n^3 + k * n^2), space: O(n^3) auxiliary (i.e. does not count output itself),
	 * where k is # of possible results
	 */
	static vector<string> removeInvalidParentheses(const string& s) {
		if (s.empty())
			return {""};
		const int n = s.size();

		/*
		 * Let dp[i][j] = the length of the longest valid parentheses subsequence in s[i...j]
		 * If this problem only ask for the length, this problem can be solved in O(n^3)
		 */
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				if (i == j) {
					dp[i][j] = (s[i] == '(' || s[i] == ')' ? 0 : 1);
				} else if (s[i] != '(') {
					dp[i][j] = dp[i + 1][j] + (s[i] == ')' ? 0 : 1);
				} else if (s[j] != ')') {
					dp[i][j] = dp[i][j - 1] + (s[j] == '(' ? 0 : 1);
				} else {
					dp[i][j] = dp[i + 1][j];
					for (int k = i + 1; k <= j; ++k) {
						if (s[k] == ')') {
							const int L1 = i + 1, R1 = k - 1, L2 = k + 1, R2 = j;
							const int len = 2 + (L1 <= R1 ? dp[L1][R1] : 0) + (L2 <= R2 ? dp[L2][R2] : 0);
							dp[i][j] = max(dp[i][j], len);
						}
					}
				}
			}
		}

		/* Backtrack every solution according to DP table */
		const auto I = single("");
		vector<vector<S>> cache(n, vector<S>(n));
		F backtrack = [&](int i, int j) -> S& {
			S& out = cache[i][j];
			if (!out.empty())
				return out;

			if (i == j) {
				out = (s[i] == '(' || s[i] == ')') ? I : single(string(1, s[i]));
			} else if (s[i] != '(') {
				out = (s[i] == ')') ? backtrack(i + 1, j) : startsWith(backtrack(i + 1, j), s[i]);
			} else if (s[j] != ')') {
				out = (s[j] == '(') ? backtrack(i, j - 1) : endsWith(backtrack(i, j - 1), s[j]);
			} else {
				if (dp[i][j] == dp[i + 1][j])
					out = backtrack(i + 1, j);
				for (int k = i + 1; k <= j; ++k) {
					if (s[k] == ')') {
						const int L1 = i + 1, R1 = k - 1, L2 = k + 1, R2 = j;
						const int len = 2 + (L1 <= R1 ? dp[L1][R1] : 0) + (L2 <= R2 ? dp[L2][R2] : 0);
						if (len == dp[i][j])
							crossJoin(out, L1 <= R1 ? backtrack(L1, R1) : I, L2 <= R2 ? backtrack(L2, R2) : I);
					}
				}
			}
			return out;
		};

		const auto& ans = backtrack(0, n - 1);
		return vector<string>(ans.begin(), ans.end());
	}
};
