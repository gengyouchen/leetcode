class Solution {
public:
	/* time: O(K*N^2), space: O(N) */
	int superEggDrop(int K, int N) {
		auto _dp = vector<vector<int>>(2, vector<int>(N + 1));
		auto dp = [&](int k, int n) -> int& { return _dp[k % 2][n]; };

		for (int k = 1; k <= K; ++k)
			for (int n = 0; n <= N; ++n)
				if (n == 0)
					dp(k, n) = 0;
				else if (k == 1)
					dp(k, n) = n;
				else {
					int best = INT_MAX;
					for (int x = 1; x <= n; ++x)
						best = min(best, 1 + max(dp(k - 1, x - 1), dp(k, n - x)));
					dp(k, n) = best;
				}
		return dp(K, N);
	}
};
