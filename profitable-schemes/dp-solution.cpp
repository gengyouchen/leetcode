class Solution {
public:
	/* time: O(N*G*P), space: O(G*P) */
	int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
		auto _dp = vector<vector<vector<long>>>(2, vector<vector<long>>(G + 1, vector<long>(P + 1)));
		auto dp = [&](int n, int g, int p) -> long& { return _dp[n % 2][g][p]; };

		const int N = group.size();
		for (int n = 0; n <= N; ++n)
			for (int g = 0; g <= G; ++g)
				for (int p = 0; p <= P; ++p) {
					if (n == 0)
						dp(n, g, p) = (p == 0) ? 1 : 0;
					else if (g < group[n - 1])
						dp(n, g, p) = dp(n - 1, g, p);
					else if (p < profit[n - 1])
						dp(n, g, p) = dp(n - 1, g, p) + dp(n - 1, g - group[n - 1], 0);
					else
						dp(n, g, p) = dp(n - 1, g, p) + dp(n - 1, g - group[n - 1], p - profit[n - 1]);

					dp(n, g, p) %= 1000000007;
				}

		return dp(N, G, P);
	}
};
