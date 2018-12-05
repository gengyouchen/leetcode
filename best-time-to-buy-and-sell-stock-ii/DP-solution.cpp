class Solution {
public:
	/* time: O(n), space: O(1) */
	int maxProfit(const vector<int>& prices) {
		if (prices.empty())
			return 0;
		const int n = prices.size();

		int _cash[2], _hold[2];
		auto cash = [&](int day) -> int& { return _cash[day % 2]; };
		auto hold = [&](int day) -> int& { return _hold[day % 2]; };

		for (int day = 0; day < n; ++day)
			if (day == 0) {
				hold(day) = -prices[day];
				cash(day) = 0;
			} else {
				hold(day) = max(hold(day - 1), cash(day - 1) - prices[day]);
				cash(day) = max(cash(day - 1), hold(day - 1) + prices[day]);
			}
		return cash(n - 1);
	}
};
