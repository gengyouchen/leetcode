class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(m*n), space: O(min(m, n)) */
	int minDistance(const string& word1, const string& word2) {
		const int m = word1.size();
		const int n = word2.size();
		if (m < n)
			return minDistance(word2, word1);

		auto _dp = V2D(2, V1D(n + 1, 0));
		auto dp = [&](int i, int j) -> int& { return _dp[i % 2][j]; };

		const int INSERT_COST = 1;
		const int DELETE_COST = 1;
		const int REPLACE_COST = 1;

		for (int i = m; i >= 0; --i)
			for (int j = n; j >= 0; --j)
				if (i == m && j == n)
					dp(i, j) = 0;
				else if (i == m)
					dp(i, j) = 1 + dp(i, j + 1);
				else if (j == n)
					dp(i, j) = 1 + dp(i + 1, j);
				else
					if (word1[i] == word2[j])
						dp(i, j) = dp(i + 1, j + 1);
					else
						dp(i, j) = min(INSERT_COST + dp(i, j + 1),
						           min(DELETE_COST + dp(i + 1, j),
						           REPLACE_COST + dp(i + 1, j + 1)));
		return dp(0, 0);
	}
};
