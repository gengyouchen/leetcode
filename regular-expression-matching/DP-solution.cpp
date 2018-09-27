class Solution {
private:
	typedef vector<bool> V1D;
	typedef vector<V1D> V2D;
	typedef V1D::reference R;
public:
	/* time: O(S*P), space: O(P) */
	bool isMatch(const string& s, const string& p) {
		const int m = s.size();
		const int n = p.size();
		auto _dp = V2D(2, V1D(n + 1, false));
		auto dp = [&](int i, int j) -> R { return _dp[i % 2][j]; };

		for (int i = m; i >= 0; --i)
			for (int j = n; j >= 0; --j) {
				if (j < n && p[j] == '*')
					continue; /* not a valid DP state */

				bool isEmptySi = (i == m);
				bool isEmptyPj = (j == n);
				bool isPjWithStar = (j + 1 < n) && (p[j + 1] == '*');

				if (isEmptySi && isEmptyPj)
					dp(i, j) = true;
				else if (isEmptySi)
					dp(i, j) = isPjWithStar && dp(i, j + 2);
				else if (isEmptyPj)
					dp(i, j) = false;
				else {
					bool isPjMatched = (p[j] == s[i]) || (p[j] == '.');
					if (isPjWithStar)
						dp(i, j) = (isPjMatched && dp(i + 1, j)) || dp(i, j + 2);
					else
						dp(i, j) = isPjMatched && dp(i + 1, j + 1);
				}
			}
		return dp(0, 0);
	}
};
