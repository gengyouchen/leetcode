class Solution {
private:
	typedef vector<string> S;
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

		/* Let dp[i][j] = the length of the longest valid parentheses subsequence in s[i...j] */
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				dp[i][j] = (s[i] == '(' || s[i] == ')' ? 0 : 1) + (i < j ? dp[i + 1][j] : 0);
				if (s[i] == '(') {
					for (int k = i + 1; k <= j; ++k) {
						if (s[k] == ')') {
							const int len = 2 + (k > i + 1 ? dp[i + 1][k - 1] : 0) + (k < j ? dp[k + 1][j] : 0);
							dp[i][j] = max(dp[i][j], len);
						}
					}
				}
			}
		}

		/* Backtrack every solution according to DP table */
		const S I{""};
		vector<vector<S>> cache(n, vector<S>(n));
		F backtrack = [&](int i, int j) -> S& {
			auto& ans = cache[i][j];
			if (!ans.empty())
				return ans;
			if (i == j) {
				if (s[i] == '(' || s[i] == ')')
					ans.emplace_back();
				else
					ans.emplace_back(1, s[i]);
			} else {
				if (s[i] == '(') {
					if (dp[i][j] == 0)
						ans.emplace_back();
					/* case 1: if the left bracket s[i] is not included */
					for (int k = i; k < j; ++k) {
						if (k < j && s[k + 1] == '(')
							continue; /* skip duplicates */
						if (dp[i][j] == dp[k + 1][j])
							ans = backtrack(k + 1, j);
						break;
					}
					/* case 2: if the left bracket s[i] is included */
					for (int k = i + 1; k <= j; ++k) {
						if (s[k] == ')') {
							if (k < j && s[k + 1] == ')')
								continue; /* skip duplicates */
							const int len = 2 + (k > i + 1 ? dp[i + 1][k - 1] : 0) + (k < j ? dp[k + 1][j] : 0);
							if (len == dp[i][j]) {
								for (const auto& a : (k > i + 1) ? backtrack(i + 1, k - 1) : I) {
									for (const auto& b : (k < j) ? backtrack(k + 1, j) : I)
										ans.push_back('(' + a + ')' + b);
								}
							}
						}
					}
				} else if (s[i] == ')') {
					ans = backtrack(i + 1, j);
				} else {
					for (const auto& str : backtrack(i + 1, j))
						ans.push_back(s[i] + str);
				}
			}
			return ans;
		};
		return backtrack(0, n - 1);
	}
};
