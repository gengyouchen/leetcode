class Solution {
public:
	/*
	 * time: O(n), space: O(1)
	 *
	 * The recursive definition of numTrees is:
	 * numTrees(0) = 1
	 * numTrees(n + 1) = sum { numTrees(i) * numTrees(n - i) for all i <= n }
	 *
	 * This is exactly the same recursive definition of the Catalan number
	 * We can use DP to calculate Catalan(n) in O(n^2) time, O(n) space
	 *
	 * The Catalan number is also defined directly in terms of binomial coefficients:
	 * Catalan(n) = C(2n, n) / (n + 1)
	 *
	 * Therefore, the ratio of Catalan(n + 1) / Catalan(n) = 2(2n + 1) / (n + 2)
	 * We can calculate Catalan(n) sequentially in O(n) time, O(1) space
	 */
	int numTrees(int n) {
		long Catalan = 1;
		for (int k = 0; k < n; ++k)
			Catalan = Catalan * 2 * (2 * k + 1) / (k + 2);
		return Catalan;
	}
};
