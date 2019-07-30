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
		int ans = 1;
		while (n >= 5)
			ans *= 3, n -= 3;
		ans *= n;

		return ans;
	}
};
