class Solution {
public:
	/* time: O(n*m), space: O(m), where n = |S|, m = |T| */
	static string minWindow(const string& S, const string& T) {
		const int n = S.size(), m = T.size();
		int ansPos = -1, ansLen = INT_MAX;

		vector<int> _dp(m * 2);
#define DP(i, j) _dp[((i) % 2) ? ((j) + m) : (j)]
		for (int i = n - 1; i >= 0; --i) {
			for (int j = m - 1; j >= 0; --j) {
				if (i == n - 1 && j == m - 1)
					DP(i, j) = (S[i] == T[j]) ? i : -1;
				else if (i == n - 1)
					DP(i, j) = -1;
				else if (j == m - 1)
					DP(i, j) = (S[i] == T[j]) ? i : DP(i + 1, j);
				else
					DP(i, j) = (S[i] == T[j]) ? DP(i + 1, j + 1) : DP(i + 1, j);
			}

			if (DP(i, 0) != -1) {
				const int len = DP(i, 0) - i + 1;
				if (len <= ansLen)
					ansPos = i, ansLen = len;
			}
		}
#undef DP
		return (ansPos == -1) ? "" : S.substr(ansPos, ansLen);
	}
};
