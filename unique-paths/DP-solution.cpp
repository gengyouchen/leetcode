class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(m*n), space: O(min(m,n)) */
	int uniquePaths(int m, int n) {
		if (m < n)
			return uniquePaths(n, m);

		auto _dp = V2D(2, V1D(n));
		auto dp = [&](int i, int j) -> int& { return _dp[i % 2][j]; };

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (i == 0 && j == 0)
					dp(i, j) = 1;
				else if (i == 0)
					dp(i, j) = dp(i, j - 1);
				else if (j == 0)
					dp(i, j) = dp(i - 1, j);
				else
					dp(i, j) = dp(i - 1, j) + dp(i, j - 1);
		return dp(m - 1, n - 1);
	}
};
