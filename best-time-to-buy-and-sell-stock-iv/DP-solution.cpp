class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
	/*
	 * If k >= n/2, you may complete as many transactions as you like.
	 * See LeetCode 122 - Best Time to Buy and Sell Stock II
	 */
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
public:
	/*
	 * time: O(n*k), space: O(k) if k < n/2
	 * time: O(n), space: O(1) if k >= n/2
	 */
	int maxProfit(int k, const vector<int>& prices) {
		if (prices.empty() || k == 0)
			return 0;
		const int n = prices.size();
		if (k >= n / 2)
			return maxProfit(prices);

		auto _cash = V2D(2, V1D(k)), _hold = V2D(2, V1D(k));
		auto cash = [&](int day, int tx) -> int& { return _cash[day % 2][tx]; };
		auto hold = [&](int day, int tx) -> int& { return _hold[day % 2][tx]; };

		for (int day = 0; day < n; ++day)
			for (int tx = 0; tx < k; ++tx)
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
		return cash(n - 1, k - 1);
	}
};
