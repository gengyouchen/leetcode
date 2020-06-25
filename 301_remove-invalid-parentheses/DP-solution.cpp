class Solution {
private:
	typedef vector<string> S;
	typedef function<S&(int, int)> F;
public:
	/*
	 * time: O(n^3 + k * n^2), space: O(n^3 + k * n^2) auxiliary (i.e. does not count output itself),
	 * where k is # of possible results
	 */
	static vector<string> removeInvalidParentheses(const string& s) {
		if (s.empty())
			return {""};
		const int n = s.size();

		/* Let dp[i][j] = the length of the longest valid parentheses subsequence in s[i...j] */
		vector<vector<int>> dp(n, vector<int>(n));
		vector<vector<vector<int>>> path(n, vector<vector<int>>(n)); /* for output all answers */
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				if (s[i] == '(') {
					/* case 1: if the left bracket is not included */
					for (int k = i + 1; k <= j; ++k) {
						if (s[k] != '(') {
							dp[i][j] = dp[k][j], path[i][j].push_back(-k);
							break;
						}
					}
					/* case 2: if the left bracket is included */
					for (int k = i + 1; k <= j; ++k) {
						if (s[k] == ')' && (k == j || s[k + 1] != ')')) {
							const int len = 2 + (k > i + 1 ? dp[i + 1][k - 1] : 0) + (k < j ? dp[k + 1][j] : 0);
							if (len > dp[i][j])
								dp[i][j] = len, path[i][j].clear();
							if (len == dp[i][j])
								path[i][j].push_back(k);
						}
					}
				} else {
					dp[i][j] = (s[i] == '(' || s[i] == ')' ? 0 : 1) + (i < j ? dp[i + 1][j] : 0);
				}
			}
		}

		/* Backtrack every answers according to DP table */
		const S empty{""};
		vector<vector<S>> cache(n, vector<S>(n));
		F backtrack = [&](int i, int j) -> S& {
			auto& ans = cache[i][j];
			if (!ans.empty())
				return ans;
			if (s[i] == '(') {
				if (path[i][j].empty()) {
					ans = empty;
				} else {
					for (int p : path[i][j]) {
						if (p < 0) {
							ans = backtrack(-p, j);
						} else {
							for (const auto& x : p > i + 1 ? backtrack(i + 1, p - 1) : empty) {
								for (const auto& y : p < j ? backtrack(p + 1, j) : empty)
									ans.push_back('(' + x + ')' + y);
							}
						}
					}
				}
			} else if (s[i] == ')') {
				ans = i < j ? backtrack(i + 1, j) : empty;
			} else {
				for (const auto& x : i < j ? backtrack(i + 1, j) : empty)
					ans.push_back(s[i] + x);
			}
			return ans;
		};
		return backtrack(0, n - 1);
	}
};
