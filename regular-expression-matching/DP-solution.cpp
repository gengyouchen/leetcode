class Solution {
private:
	typedef vector<bool> V1D;
	typedef vector<V1D> V2D;
	typedef V1D::reference R;
public:
	/* time: O(len(s) * len(p)), space: O(len(p)) */
	bool isMatch(const string& s, const string& p) {
		const int m = s.size(), n = p.size();
		auto _dp = V2D(2, V1D(n + 1, false));
		auto dp = [&](int i, int j) -> R { return _dp[i % 2][j]; };

		for (int i = m; i >= 0; --i)
			for (int j = n; j >= 0; --j) {
				if (j < n && p[j] == '*')
					continue; /* not a valid DP state */
				const bool withStar = (j + 1 < n) && (p[j + 1] == '*');

				if ((i == m) && (j == n))
					dp(i, j) = true;
				else if (i == m)
					dp(i, j) = withStar && dp(i, j + 2);
				else if (j == n)
					dp(i, j) = false;
				else {
					const bool matched = (p[j] == s[i]) || (p[j] == '.');
					if (withStar)
						dp(i, j) = (matched && dp(i + 1, j)) || dp(i, j + 2);
					else
						dp(i, j) = matched && dp(i + 1, j + 1);
				}
			}
		return dp(0, 0);
	}
};
