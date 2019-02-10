class Solution {
private:
	vector<int> kmpTable(const string& s) {
		/*
		 * How to generate the KMP table in O(n) time?
		 *
		 *                    prefix   suffix
		 *                    =====    =====
		 * e.g. when i=13, s="ababa9487ababa...", ans=5 (matched length)
		 *                        ^        ^
		 *                                 i=13
		 *
		 *                    =====    =====
		 * Now, when i=14, s="ababa9487ababab..."
		 *                         ^        ^
		 *                                  i=14
		 *
		 * Because '9' != 'b', we cannot ++ans anymore
		 * However, we do NOT need to restart ans=0
		 *
		 *                                   ===
		 *                                     ===
		 * Reuse the previous i=4 result of "ababa...", ans=3 (matched length)
		 *                                     ^ ^
		 *                                       i=4
		 *
		 *                               ===        ===
		 * We can restart from ans=3, s="ababa9487ababab..."
		 *                                  ^          ^
		 *                                             i=14
		 *
		 * Because 'b' == 'b', we can now ++ans
		 *
		 *                    ====       ====
		 * Now, when i=15, s="ababa9487ababab...", ans=4 (matched length)
		 *                                  ^
		 *                                  i=15
		 */
		const int n = s.size();
		vector<int> dp(n);
		dp[0] = 0;
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			while (ans > 0 && s[ans] != s[i])
				ans = dp[ans - 1];
			if (s[ans] == s[i])
				++ans;
			dp[i] = ans;
		}
		return dp;
	}
public:
	/* time: O(m+n), space: O(n), where m=len(haystack), n=len(needle) */
	int strStr(const string& haystack, const string& needle) {
		if (needle.empty())
			return 0;
		const int m = haystack.size(), n = needle.size();
		const auto LPS = kmpTable(needle);
		int nMatched = 0;
		for (int i = 0; i < m; ++i) {
			while (nMatched > 0 && needle[nMatched] != haystack[i])
				nMatched = LPS[nMatched - 1];
			if (needle[nMatched] == haystack[i])
				++nMatched;
			if (nMatched == n) {
				return i - nMatched + 1; /* found */
				nMatched = LPS[nMatched - 1]; /* find next */
			}
		}
		return -1; /* not found */
	}
};
