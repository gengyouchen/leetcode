class Solution {
private:
	struct V2P {
		int valley, peak;
		int profit() const { return peak - valley; }
	};
public:
	/* time: O(n), space: O(n) */
	int maxProfit(int k, const vector<int>& prices) {
		const int n = prices.size();

		/* Find out all profit opportunities */
		vector<int> profits;
		stack<V2P> prev;
		for (auto it = prices.begin();;) {
			it = is_sorted_until(it, prices.end(), greater<int>());
			if (it == prices.end())
				break;
			V2P curr;
			curr.valley = *(it - 1);
			it = is_sorted_until(it, prices.end());
			curr.peak = *(it - 1);

			/*
			 * See https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54145/
			 *     This is a super brilliant idea!
			 *
			 * The key insight is:
			 *     for 2 valley-to-peak pair: prev(v1, p1) and curr(v2, p2),
			 *     if v1 < v2 and p1 < p2,
			 *     we can merge them into one pair (v1, p2) with additional profit opportunities (p1 - v2)
			 */
			while (!prev.empty() && !(curr.valley > prev.top().valley))
				profits.push_back(prev.top().profit()), prev.pop();
			while (!prev.empty() && curr.peak > prev.top().peak)
				profits.push_back(prev.top().peak - curr.valley), curr.valley = prev.top().valley, prev.pop();
			prev.push(curr);
		}
		while (!prev.empty())
			profits.push_back(prev.top().profit()), prev.pop();

		/* Select top-k profit opportunities */
		if (profits.size() <= k)
			return accumulate(profits.begin(), profits.end(), 0);
		nth_element(profits.begin(), profits.end() - k, profits.end());
		return accumulate(profits.end() - k, profits.end(), 0);
	}
};
