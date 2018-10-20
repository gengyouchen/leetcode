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
			for (int j = n; j >= 0; --j)
				if ((i == m) && (j == n))
					dp(i, j) = true;
				else if (i == m)
					dp(i, j) = (p[j] == '*') && dp(i, j + 1);
				else if (j == n)
					dp(i, j) = false;
				else {
					const bool matched = (p[j] == s[i]) || (p[j] == '?') || (p[j] == '*');
					if (p[j] == '*')
						dp(i, j) = (matched && dp(i + 1, j)) || dp(i, j + 1);
					else
						dp(i, j) = matched && dp(i + 1, j + 1);
				}
		return dp(0, 0);
	}
};
