class Solution {
private:
	enum Color { RED = 0, BLUE = 1, GREEN = 2 };
public:
	/* time: O(n), space: O(1) */
	int minCost(const vector<vector<int>>& costs) {
		if (costs.empty())
			return 0;
		const int n = costs.size();

		int _dp[2][3];
		auto dp = [&](int i, int color) -> int& { return _dp[i % 2][color]; };

		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				dp(i, RED) = costs[i][RED];
				dp(i, BLUE) = costs[i][BLUE];
				dp(i, GREEN) = costs[i][GREEN];
			} else {
				dp(i, RED) = min(dp(i - 1, BLUE), dp(i - 1, GREEN)) + costs[i][RED];
				dp(i, BLUE) = min(dp(i - 1, RED), dp(i - 1, GREEN)) + costs[i][BLUE];
				dp(i, GREEN) = min(dp(i - 1, RED), dp(i - 1, BLUE)) + costs[i][GREEN];
			}
		}
		return min(dp(n - 1, RED), min(dp(n - 1, BLUE), dp(n - 1, GREEN)));
	}
};
