class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(n^2), space: O(n) */
	int longestPalindromeSubseq(const string& s) {
		auto _dp = V2D(2, V1D(s.size()));
		auto dp = [&](int i, int j) -> int& { return _dp[i % 2][j]; };

		for (int i = s.size() - 1; i >= 0; --i)
			for (int j = i; j < s.size(); ++j)
				if (i == j)
					dp(i, j) = 1;
				else if (i + 1 == j)
					dp(i, j) = (s[i] == s[j]) ? 2 : 1;
				else
					dp(i, j) = (s[i] == s[j]) ? dp(i + 1, j - 1) + 2 : max(dp(i + 1, j), dp(i, j - 1));
		return dp(0, s.size() - 1);
	}
};
