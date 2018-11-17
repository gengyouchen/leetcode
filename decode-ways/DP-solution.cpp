class Solution {
public:
	/* time: O(len(s)), space: O(1) */
	int numDecodings(const string& s) {
		const int n = s.size();
		int _dp[2];
		auto dp = [&](int i) -> int& { return _dp[i % 2]; };

		for (int i = n - 1; i >= 0; --i) {
			const int a2j = (s[i] != '0') ? 1 : 0;
			const int k2z = (i + 1 < n) && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') ? 1 : 0;
			if (i == n - 1)
				dp(i) = a2j;
			else if (i == n - 2)
				dp(i) = a2j * dp(i + 1) + k2z;
			else
				dp(i) = a2j * dp(i + 1) + k2z * dp(i + 2);
		}
		return dp(0);
	}
};
