class Solution {
public:
	/* time: O(n), space: O(1) */
	int numWays(int n, int k) {
		if (k == 0 || n == 0)
			return 0;
		if (k == 1)
			return (n < 3) ? 1 : 0;

		int _dp[3];
		auto dp = [&](int i) -> int& { return _dp[i % 3]; };

		for (int i = 1; i <= n; ++i) {
			if (i == 1)
				dp(i) = k;
			else if (i == 2)
				dp(i) = k * k;
			else
				dp(i) = (dp(i - 1) + dp(i - 2)) * (k - 1);
		}
		return dp(n);
	}
};
