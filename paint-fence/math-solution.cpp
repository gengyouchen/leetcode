class Solution {
public:
	/*
	 * time: O(1), space: O(1),
	 * assuming sqrt(x) and pow(x, a) are all O(1) time
	 */
	int numWays(int n, int k) {
		if (k == 0 || n == 0)
			return 0;
		if (k == 1)
			return (n < 3) ? 1 : 0;
		/*
		 * In the DP solution, we have:
		 * dp(1) = k
		 * dp(2) = k^2
		 * dp(n) = (dp(n - 1) + dp(n - 2)) * (k - 1)
		 *
		 * In the Lucas sequence, if we let P = (k - 1), Q = -P, we have:
		 * U(0) = 0
		 * U(1) = 1
		 * U(n) = (U(n - 1) + U(n - 2)) * (k - 1)
		 *
		 * dp(n) must have some relationships with U(n).
		 * Let's see more examples:
		 * |                                     | U(0) = 0                         |
		 * |                                     | U(1) = 1                         |
		 * | dp(1) = k                           | U(2) = (k - 1)                   |
		 * | dp(2) = k^2                         | U(3) = (k - 1) * k               |
		 * | dp(3) = (k - 1) * k * (k + 1)       | U(4) = (k - 1)^2 * (k + 1)       |
		 * | dp(4) = (k - 1) * k * (k^2 + k - 1) | U(5) = (k - 1)^2 * (k^2 + k - 1) |
		 * | ...                                 | ...                              |
		 *
		 * Therefore, dp(n) = U(n + 1) * k / (k - 1)
		 *
		 * We can directly calculate U(n) = (a^n - b^n) / D^0.5
		 * where D = P^2 - 4*Q, a = (P + D^0.5) / 2, b = (P - D^0.5) / 2
		 * (See https://en.wikipedia.org/wiki/Lucas_sequence#Explicit_expressions)
		 */
		const long double P = k - 1, Q = -P, D = P * P - 4 * Q;
		const long double a = (P + sqrt(D)) / 2, b = (P - sqrt(D)) / 2;
		const long double U = (pow(a, n + 1) - pow(b, n + 1)) / sqrt(D);
		return round(U * k / (k - 1));
	}
};
