class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(m*n), space: O(n), where m = len(s), n = len(t) */
	int numDistinct(const string& s, const string& t) {
		const int m = s.size(), n = t.size();
		auto _dp = V2D(2, V1D(n + 1));
		auto dp = [&](int i, int j) -> int& { return _dp[i % 2][j]; };

		for (int i = 0; i <= m; ++i)
			for (int j = 0; j <= n; ++j)
				if (i == 0 && j == 0)
					dp(i, j) = 1;
				else if (i == 0)
					dp(i, j) = 0;
				else if (j == 0)
					dp(i, j) = 1;
				else
					dp(i, j) = (s[i - 1] == t[j - 1]) ? dp(i - 1, j - 1) + dp(i - 1, j) : dp(i - 1, j);
		return dp(m, n);
	}
};
