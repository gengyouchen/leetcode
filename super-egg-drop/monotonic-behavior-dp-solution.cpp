class Solution {
public:
	/* time: O(K*N), space: O(N) */
	int superEggDrop(int K, int N) {
		auto _dp = vector<vector<int>>(2, vector<int>(N + 1));
		auto dp = [&](int k, int n) -> int& { return _dp[k % 2][n]; };

		for (int k = 1; k <= K; ++k) {
			int x = 1;
			for (int n = 0; n <= N; ++n)
				if (n == 0)
					dp(k, n) = 0;
				else if (k == 1)
					dp(k, n) = n;
				else {
					/*
					 * T1(x) = dp(k-1, x-1) is monotonically increasing
					 * T2(x) = dp(k, n-x) is monotonically decreasing
					 * To minimize max(T1(x), T2(x)),
					 * find the smallest x value such that T2(x) <= T1(x)
					 *
					 * Consider previous result (i.e. for n-1) as x'
					 * When n is now increased by 1,
					 * T1(x') won't change, and T2(x') won't decrease,
					 * so in order to still satisfy T2(x) <= T1(x),
					 * x must >= x' (i.e. cannot decrease)
					 */
					while (x < n && dp(k, n - x) > dp(k - 1, x - 1))
						++x;
					dp(k, n) = 1 + max(dp(k - 1, x - 1), dp(k, n - x));
				}
		}
		return dp(K, N);
	}
};
