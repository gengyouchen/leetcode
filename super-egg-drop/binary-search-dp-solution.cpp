class Solution {
private:
	template <class I, class F>
	I findFirstTrue(I first, I last, F cond) {
		while (first != last) {
			I mid = first + (last - first) / 2;
			if (cond(mid))
				last = mid;
			else
				first = mid + 1;
		}
		return first;
	}
public:
	/* time: O(K*N*log(N)), space: O(N) */
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
					/*
					 * T1(x) = dp(k-1, x-1) is monotonically increasing
					 * T2(x) = dp(k, n-x) is monotonically decreasing
					 * To minimize max(T1(x), T2(x)),
					 * find the smallest x value such that T2(x) <= T1(x)
					 */
					int x = findFirstTrue(1, n, [&](auto x) {
						return dp(k, n - x) <= dp(k - 1, x - 1);
					});
					dp(k, n) = 1 + max(dp(k - 1, x - 1), dp(k, n - x));
				}
		return dp(K, N);
	}
};
