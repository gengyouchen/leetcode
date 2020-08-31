class Solution {
private:
	typedef vector<bool> V1D;
	typedef vector<V1D> V2D;
	typedef V1D::reference R;
public:
	/* time: O(n^2), space: O(n) */
	string longestPalindrome(const string& s) {
		auto _dp = V2D(2, V1D(s.size()));
		auto dp = [&](int i, int j) -> R { return _dp[i % 2][j]; };

		int L = 0, R = 0;
		for (int i = s.size() - 1; i >= 0; --i)
			for (int j = i; j < s.size(); ++j) {
				if (i == j)
					dp(i, j) = true;
				else if (i + 1 == j)
					dp(i, j) = (s[i] == s[j]);
				else
					dp(i, j) = (s[i] == s[j]) && dp(i + 1, j - 1);

				if (dp(i, j) && j - i > R - L)
					L = i, R = j;
			}
		return s.substr(L, R - L + 1);
	}
};
