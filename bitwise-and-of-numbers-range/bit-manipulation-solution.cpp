class Solution {
public:
	/* time: O(1), space: O(1) */
	int rangeBitwiseAnd(int m, int n) {
		/*
		 * Treat 32-bit m as [ HigherBits | LowerBits ],
		 *       32-bit n as [ HigherBits | LowerBits ]
		 * such that their HigherBits are the same,
		 * and the MSB of LowerBits is '0' -> '1'.
		 *
		 * The answer will be [ HigherBits | 0 ... 0 ],
		 */
		int nLowerBits = 0;
		while (m != n)
			m >>= 1, n >>= 1, ++nLowerBits;
		return n << nLowerBits;
	}
};
