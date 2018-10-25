class Solution {
private:
	typedef vector<TreeNode*> Roots;
	typedef vector<Roots> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(Catalan(n)), space: O(Catalan(n)) */
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return Roots();

		const Roots empty { NULL };
		auto dp = V2D(n + 1, V1D(n + 1));

		auto generate = [&](int L, int R) {
			/* time: O(sum{Catalan(i-L)*Catalan(R-i) for all i in [L,R]}) = O(Catalan(R-L+1)) */
			for (int i = L; i <= R; ++i) {
				const auto& A = (i > L) ? dp[L][i - 1] : empty;
				const auto& B = (i < R) ? dp[i + 1][R] : empty;

				/* time: O(len(A)*len(B)) = O(Catalan(i-L)*Catalan(R-i)) */
				for (auto a : A) {
					for (auto b : B) {
						auto root = new TreeNode(i);
						root->left = a, root->right = b;
						dp[L][R].push_back(root);
					}
				}
			}
		};

		/*
		 * time: O(1*Catalan(n) + 2*Catalan(n-1) + 3*Catalan(n-2) + 4*Catalan(n-3) + 5*Catalan(n-4) + 6*Catalan(n-5)...)
		 *         ^              ^                ^                ^                ^                ^
		 *         dp[1][n]       dp[1][n-1]       dp[1][n-2]       dp[1][n-3]       dp[1][n-4]       dp[1][n-5]
		 *                        dp[2][n]         dp[2][n-1]       dp[2][n-2]       dp[2][n-3]       dp[2][n-4]
		 *                                         dp[3][n]         dp[3][n-1]       dp[3][n-2]       dp[3][n-3]
		 *                                                          dp[4][n]         dp[4][n-1]       dp[4][n-2]
		 *                                                                           dp[5][n]         dp[5][n-1]
		 *                                                                                            dp[6][n]
		 *       <= O(1*Catalan(n) + 3*Catalan(n)) ... see the proof below
		 *        = O(Catalan(n))
		 *
		 * <Proof>
		 * Recall the recursive definition of Catalan number:
		 * Catalan(n) = Catalan(0)*Catalan(n-1) + Catalan(1)*Catalan(n-2) + Catalan(2)*Catalan(n-3)...
		 *            = 1*Catalan(n-1) + 1*Catalan(n-2) + 2*Catalan(n-3) + 5*Catalan(n-4) + 14*Catalan(n-5)...
		 *
		 * For 3*Catalan(n), it's obvious that every coefficient 3*Catalan(i) >= (i + 2):
		 * 3*Catalan(n) = 3*Catalan(n-1) + 3*Catalan(n-2) + 6*Catalan(n-3) + 15*Catalan(n-4) + 42*Catalan(n-5)...
		 *             >= 2*Catalan(n-1) + 3*Catalan(n-2) + 4*Catalan(n-3) +  5*Catalan(n-4) +  6*Catalan(n-5)...
		 */
		for (int L = n; L >= 1; --L)
			for (int R = L; R <= n; ++R)
				generate(L, R);
		return dp[1][n];
	}
};
