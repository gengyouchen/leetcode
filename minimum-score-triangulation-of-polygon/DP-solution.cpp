class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(n^3), space: O(n^2) */
	static int minScoreTriangulation(const vector<int>& A) {
		const int n = A.size();
		V2D dp(n, V1D(n));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i + 2; j < n; ++j) {
				dp[i][j] = INT_MAX;
				for (int k = i + 1; k < j; ++k)
					dp[i][j] = min(dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
			}
		}
		return dp[0][n - 1];
	}
};
