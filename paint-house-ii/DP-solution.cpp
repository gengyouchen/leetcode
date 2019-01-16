class Solution {
private:
	struct State { int color, cost; };
public:
	/* time: O(n*k), space: O(1) */
	int minCostII(const vector<vector<int>>& costs) {
		if (costs.empty())
			return 0;
		const int n = costs.size(), k = costs[0].size();

		State _dp[2][2];
		auto dp = [&](int i, int rank) -> State& { return _dp[i % 2][rank]; };

		for (int i = 0; i < n; ++i) {
			dp(i, 0).color = dp(i, 1).color = -1;
			for (int color = 0; color < k; ++color) {
				State curr;
				curr.color = color;
				if (i == 0)
					curr.cost = costs[i][color];
				else
					curr.cost = costs[i][color] + ((dp(i - 1, 0).color != color) ? dp(i - 1, 0).cost : dp(i - 1, 1).cost);

				if (dp(i, 0).color == -1 || curr.cost < dp(i, 0).cost)
					dp(i, 1) = dp(i, 0), dp(i, 0) = curr;
				else if (dp(i, 1).color == -1 || curr.cost < dp(i, 1).cost)
					dp(i, 1) = curr;
			}
		}
		return min(dp(n - 1, 0).cost, dp(n - 1, 1).cost);
	}
};
