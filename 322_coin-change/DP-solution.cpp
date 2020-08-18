class Solution {
public:
	/* time: O(amount * len(coins)), space: O(min(amount, max(coins))) */
	static int coinChange(const vector<int>& coins, int amount) {
		if (coins.empty())
			return (amount == 0) ? 0 : -1;
		const int W = 1 + min(amount, *max_element(coins.begin(), coins.end()));
		vector<int> _dp(W);

#define DP(i) _dp[(i) % W]
		for (int i = 1; i <= amount; ++i) {
			DP(i) = INT_MAX;
			for (int coin : coins) {
				if (i - coin >= 0 && DP(i - coin) != INT_MAX)
					DP(i) = min(DP(i), DP(i - coin) + 1);
			}
		}
		return (DP(amount) == INT_MAX) ? -1 : DP(amount);
#undef DP
	}
};
