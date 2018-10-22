class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(m * n), space: O(min(m, n)), where m = len(s1), n = len(s2) */
	bool isInterleave(const string& s1, const string& s2, const string& s3) {
		const int m = s1.size(), n = s2.size(), t = s3.size();
		if (m + n != t)
			return false;
		if (m < n)
			return isInterleave(s2, s1, s3);

		auto _dp = V2D(2, V1D(n + 1));
		auto dp = [&](int i, int j) -> int& { return _dp[i % 2][j]; };

		for (int i = 0; i <= m; ++i)
			for (int j = 0; j <= n; ++j)
				if (i == 0 && j == 0)
					dp(i, j) = true;
				else if (i == 0)
					dp(i, j) = (s2[j - 1] == s3[j - 1]) && dp(i, j - 1);
				else if (j == 0)
					dp(i, j) = (s1[i - 1] == s3[i - 1]) && dp(i - 1, j);
				else
					dp(i, j) = ((s1[i - 1] == s3[i + j - 1]) && dp(i - 1, j)) || ((s2[j - 1] == s3[i + j - 1]) && dp(i, j - 1));
		return dp(m, n);
	}
};
