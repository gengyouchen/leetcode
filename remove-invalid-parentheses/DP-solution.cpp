static vector<string> operator+(const vector<string>& s, char c) {
	vector<string> ret;
	for (const auto& it : s)
		ret.push_back(it + c);
	return ret;
}
static vector<string> operator+(char c, const vector<string>& s) {
	vector<string> ret;
	for (const auto& it : s)
		ret.push_back(c + it);
	return ret;
}

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
		const S I{""};
		vector<vector<S>> cache(n, vector<S>(n));
		F backtrack = [&](int i, int j) -> S& {
			auto& out = cache[i][j];
			if (!out.empty())
				return out;

			if (i == j) {
				out = (s[i] == '(' || s[i] == ')') ? I : S{{ s[i] }};
			} else if (s[i] != '(') {
				out = (s[i] == ')') ? backtrack(i + 1, j) : s[i] + backtrack(i + 1, j);
			} else if (s[j] != ')') {
				out = (s[j] == '(') ? backtrack(i, j - 1) : backtrack(i, j - 1) + s[j];
			} else {
				/* case 1: if the left bracket s[i] is not included */
				for (int k = i + 1; k <= j; ++k) {
					if (s[k] != '(') /* skip duplicates */ {
						if (dp[i][j] == dp[k][j])
							out = backtrack(k, j);
						break;
					}
				}
				/* case 2: if the left-most bracket s[i] is included */
				for (int k = i + 1; k <= j; ++k) {
					if (s[k] == ')') {
						if (k + 1 <= j && s[k + 1] == ')')
							continue; /* skip duplicates */
						const int len1 = (i + 1 <= k - 1) ? dp[i + 1][k - 1] : 0;
						const int len2 = (k + 1 <= j) ? dp[k + 1][j] : 0;
						if (1 + len1 + 1 + len2 == dp[i][j]) {
							for (const auto& a : (i + 1 <= k - 1) ? backtrack(i + 1, k - 1) : I) {
								for (const auto& b : (k + 1 <= j) ? backtrack(k + 1, j) : I)
									out.push_back('(' + a + ')' + b);
							}
						}
					}
				}
			}
			return out;
		};
		return backtrack(0, n - 1);
	}
};
