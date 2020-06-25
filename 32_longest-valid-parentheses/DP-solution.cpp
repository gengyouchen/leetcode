class Solution {
public:
	/* time: O(n), space: O(n) */
	int longestValidParentheses(const string& s) {
		int ans = 0;
		vector<int> dp(s.size()); /* dp[i] = len(longest valid substring ending at s[i]) */
		for (int i = 0; i < s.size(); ++i) {
			if (i == 0)
				dp[i] = 0;
			else if (i == 1)
				dp[i] = (s[i - 1] == '(' && s[i] == ')') ? 2 : 0;
			else {
				const int j = i - dp[i - 1] - 1;
				if (j < 0)
					dp[i] = 0;
				else if (j == 0)
					dp[i] = (s[j] == '(' && s[i] == ')') ? (1 + dp[i - 1] + 1) : 0;
				else
					dp[i] = (s[j] == '(' && s[i] == ')') ? (1 + dp[i - 1] + 1 + dp[j - 1]) : 0;
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
