class Solution {
public:
	/* time: O(n^2), space: O(n) auxiliary (i.e. does not count output itself) */
	int minCut(const string& s) {
		const int n = s.size();
		/*
		 * Because doing DP for finding minimum cuts will take O(n^2) time,
		 * using Manacher's algorithm (time: O(n)) won't improve any time complexity.
		 *
		 * Therefore, we just use a simple expand-around-center method (time: O(n^2)).
		 * See LeetCode 5 - Longest Palindromic Substring
		 */
		const int len = n * 2 + 1;
		vector<int> r(len, 1);
		for (int i = 0; i < len; ++i) {
			while (i - r[i] >= 0 && i + r[i] < len) {
				if ((i - r[i]) % 2) {
					const int L = (i - r[i]) / 2, R = (i + r[i]) / 2;
					if (s[L] != s[R])
						break;
				}
				++r[i];
			}
		}
		auto isPalindrome = [&](int first, int last) {
			const int L = first * 2, R = last * 2, c = (L + R) / 2;
			return (r[c] * 2 - 1) >= (R - L + 1);
		};

		vector<int> dp(n, INT_MAX);
		for (int R = 0; R < n; ++R) {
			for (int L = 0; L <= R; ++L) {
				if (isPalindrome(L, R + 1)) {
					if (L == 0)
						dp[R] = min(dp[R], 0);
					else
						dp[R] = min(dp[R], dp[L - 1] + 1);
				}
			}
		}
		return dp[n - 1];
	}
};
