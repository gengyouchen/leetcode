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
	/* time: O(n), space: O(n) */
	string shortestPalindrome(const string& s) {
		string rev(s);
		reverse(rev.begin(), rev.end());
		const int LPS = kmpTable(s + "#" + rev).back();
		return rev.substr(0, s.size() - LPS) + s;
	}
};
