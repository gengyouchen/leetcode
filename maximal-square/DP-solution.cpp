class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(m*n), space: O(n), where m = # of rows, n = # of columns */
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();

		auto _dp = V2D(2, V1D(n));
		auto dp = [&](int i, int j) -> int& { return _dp[i % 2][j]; };

		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 || j == 0)
					dp(i, j) = (matrix[i][j] == '1') ? 1 : 0;
				else
					dp(i, j) = (matrix[i][j] == '1') ? (min(min(dp(i, j - 1), dp(i - 1, j)), dp(i - 1, j - 1)) + 1) : 0;
				ans = max(ans, dp(i, j));
			}
		}
		return ans * ans;
	}
};
