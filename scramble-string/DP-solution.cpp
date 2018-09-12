class Solution {
private:
	typedef vector<bool> V1D;
	typedef vector<V1D> V2D;
	typedef vector<V2D> V3D;
public:
	/* time: O(n^4), space: O(n^3) */
	bool isScramble(const string& s1, const string& s2) {
		const int n = s1.size();
		auto dp = V3D(n, V2D(n, V1D(n + 1)));
		for (int pos1 = n - 1; pos1 >= 0; --pos1)
			for (int pos2 = n - 1; pos2 >= 0; --pos2)
				for (int len = 1; len <= n - max(pos1, pos2); ++len)
					if (len == 1)
						dp[pos1][pos2][len] = (s1[pos1] == s2[pos2]);
					else {
						/* split len = L + R */
						dp[pos1][pos2][len] = false;
						for (int L = 1; L <= len - 1; ++L) {
							int R = len - L;
							if (dp[pos1][pos2][L] && dp[pos1 + L][pos2 + L][R]) {
								dp[pos1][pos2][len] = true;
								break;
							}
							if (dp[pos1][pos2 + R][L] && dp[pos1 + L][pos2][R]) {
								dp[pos1][pos2][len] = true;
								break;
							}
						}
					}
		return dp[0][0][n];
	}
};
