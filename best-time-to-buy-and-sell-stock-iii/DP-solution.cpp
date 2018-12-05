class Solution {
public:
	/* time: O(n), space: O(1) */
	int maxProfit(const vector<int>& prices) {
		if (prices.empty())
			return 0;
		const int n = prices.size();

		int _cash[2][2], _hold[2][2];
		auto cash = [&](int day, int tx) -> int& { return _cash[day % 2][tx]; };
		auto hold = [&](int day, int tx) -> int& { return _hold[day % 2][tx]; };

		for (int day = 0; day < n; ++day)
			for (int tx = 0; tx < 2; ++tx)
				if (day == 0) {
					hold(day, tx) = -prices[day];
					cash(day, tx) = 0;
				} else if (tx == 0) {
					hold(day, tx) = max(hold(day - 1, tx), -prices[day]);
					cash(day, tx) = max(cash(day - 1, tx), hold(day - 1, tx) + prices[day]);
				} else {
					hold(day, tx) = max(hold(day - 1, tx), cash(day - 1, tx - 1) - prices[day]);
					cash(day, tx) = max(cash(day - 1, tx), hold(day - 1, tx) + prices[day]);
				}
		return cash(n - 1, 1);
	}
};
