class Solution {
public:
	/* time: O(n ^ 0.5), space: O(1) */
	static int numSquares(int n) {
		/*
		 * See the Legendre's 3-square theorem:
		 * https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
		 */
		while (n % 4 == 0)
			n /= 4;
		const bool is3SquareSum = (n % 8 != 7);

		/*
		 * See the sum of 2 squares theorem:
		 * https://en.wikipedia.org/wiki/Sum_of_two_squares_theorem
		 */
		bool is2SquareSum = true, isSquare = true;
		for (int base = 2; base <= n; ++base) {
			if (base > n / base)
				base = n;
			int exponent = 0;
			while (n % base == 0)
				n /= base, ++exponent;

			if (exponent % 2) {
				isSquare = false;
				if (base % 4 == 3)
					is2SquareSum = false;
			}
		}

		/*
		 * See the Lagrange's 4-square theorem:
		 * https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
		 */
		return isSquare ? 1 : is2SquareSum ? 2 : is3SquareSum ? 3 : 4;
	}
};
