class Solution {
public:
	/* time: O(len(s)), space: O(1) */
	int numDecodings(const string& s) {
		const int n = s.size();
		long _dp[2];
		auto dp = [&](int i) -> long& { return _dp[i % 2]; };

		for (int i = n - 1; i >= 0; --i) {
			const long a2j = (s[i] != '0') ? (s[i] == '*') ? 9 : 1 : 0;
			const long k2z = (i + 1 < n) ? (
				((s[i] == '1' || s[i] == '*') ? (s[i + 1] == '*') ? 9 : 1 : 0) +
				(((s[i] == '2' || s[i] == '*') && s[i + 1] <= '6') ? (s[i + 1] == '*') ? 6 : 1 : 0)
			) : 0;
			if (i == n - 1)
				dp(i) = a2j;
			else if (i == n - 2)
				dp(i) = a2j * dp(i + 1) + k2z;
			else
				dp(i) = a2j * dp(i + 1) + k2z * dp(i + 2);
			dp(i) %= 1000000007;
		}
		return dp(0);
	}
};
