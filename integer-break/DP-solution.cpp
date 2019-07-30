class Solution {
public:
	/* time: O(n), space: O(1) */
	static int integerBreak(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;

		/*
		 * If an optimal product contains a factor X >= 5,
		 * we can always replace X with (X - 3) * 3 without getting worse result.
		 */
		int _dp[4];
#define DP(i) _dp[(i) % 4]
		DP(2) = 2, DP(3) = 3, DP(4) = 4;
		for (int i = 5; i <= n; ++i)
			DP(i) = DP(i - 3) * 3;
		return DP(n);
#undef DP
	}
};
