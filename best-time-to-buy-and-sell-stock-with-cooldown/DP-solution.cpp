class Solution {
public:
	/* time: O(n), space: O(1) */
	static int maxProfit(const vector<int>& prices) {
		if (prices.empty())
			return 0;
		const int n = prices.size();

		int _hold[2], _cash[3];
		auto hold = [&](int day) -> auto& { return _hold[day % 2]; };
		auto cash = [&](int day) -> auto& { return _cash[day % 3]; };

		for (int day = 0; day < n; ++day) {
			if (day == 0) {
				hold(day) = -prices[day];
				cash(day) = 0;
			} else if (day == 1) {
				hold(day) = max(hold(day - 1), -prices[day]);
				cash(day) = max(cash(day - 1), hold(day - 1) + prices[day]);
			} else {
				hold(day) = max(hold(day - 1), cash(day - 2) - prices[day]);
				cash(day) = max(cash(day - 1), hold(day - 1) + prices[day]);
			}
		}
		return cash(n - 1);
	}
};
