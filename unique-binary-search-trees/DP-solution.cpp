class Solution {
public:
	/*
	 * time: O(n^2), space: O(n)
	 *
	 * The recursive definition of numTrees is:
	 * numTrees(0) = 1
	 * numTrees(n + 1) = sum { numTrees(i) * numTrees(n - i) for all i <= n }
	 *
	 * This is exactly the same recursive definition of the Catalan number
	 */
	int numTrees(int n) {
		int ans = 0;
		vector<int> Catalan(n + 1, 0);
		Catalan[0] = 1;
		for (int k = 0; k < n; ++k)
			for (int i = 0; i <= k; ++i)
				Catalan[k + 1] += Catalan[i] * Catalan[k - i];
		return Catalan[n];
	}
};
