class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(n^2), space: O(n), where n = # of rows */
	int minimumTotal(const vector<vector<int>>& triangle) {
		const int n = triangle.size();
		auto _dp = V2D(2, V1D(n));
		auto dp = [&](int row, int col) -> int& { return _dp[row % 2][col]; };

		for (int row = n - 1; row >= 0; --row)
			for (int col = 0; col <= row; ++col)
				if (row == n - 1)
					dp(row, col) = triangle[row][col];
				else
					dp(row, col) = triangle[row][col] + min(dp(row + 1, col), dp(row + 1, col + 1));
		return dp(0, 0);
	}
};
