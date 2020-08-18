class Solution {
private:
	typedef function<void(int, int, int)> F;
public:
	/* time: O(2 ^ k), space: O(k), where k = amount / min(coins) + len(coins) */
	static int coinChange(vector<int>& coins, int amount) {
		const int n = coins.size();
		sort(coins.begin(), coins.end(), greater<int>());

		int ans = INT_MAX;
		F backtrack = [&](int step, int remaining, int nCoins) {
			if (remaining == 0) {
				ans = min(ans, nCoins);
			} else if (step < n) {
				for (int i = remaining / coins[step]; i >= 0; --i) {
					if (nCoins + i >= ans) /* pruning */
						break;
					backtrack(step + 1, remaining - i * coins[step], nCoins + i);
				}
			}
		};
		backtrack(0, amount, 0);
		return (ans == INT_MAX) ? -1 : ans;
	}
};
