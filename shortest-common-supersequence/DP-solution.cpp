class Solution {
public:
	/* time: O(m*n), space: O(m*n) */
	static string shortestCommonSupersequence(const string& str1, const string& str2) {
		const int m = str1.size(), n = str2.size();

		/*
		 * Use DP to find the LCS between str1[:i] and str2[:j]
		 * See CLRS textbook 15.4: Longest Common Subsequence
		 */
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		/*
		 * When backtracking the DP table from (m, n) back to (0, 0)...
		 * 1. If we output only the common characters, we get the Longest Common Subsequence
		 * 2. If we output every characters, we get the Shortest Common Supersequence
		 */
		string ans;
		int i = m, j = n;
		while (i > 0 || j > 0) {
			if (i == 0)
				ans.push_back(str2[--j]);
			else if (j == 0)
				ans.push_back(str1[--i]);
			else if (str1[i - 1] == str2[j - 1])
				ans.push_back(str1[--i]), --j;
			else if (dp[i - 1][j] > dp[i][j - 1])
				ans.push_back(str1[--i]);
			else
				ans.push_back(str2[--j]);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
