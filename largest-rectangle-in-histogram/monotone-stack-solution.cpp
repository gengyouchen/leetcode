class Solution {
private:
	typedef vector<int>::iterator I;
public:
	/* time: O(n), space: O(n) */
	int largestRectangleArea(vector<int>& heights) {
		heights.insert(heights.begin(), -1);
		heights.push_back(0);

		int ans = 0;
		stack<I> mono; /* Monotone Stack */
		for (auto it = heights.begin(); it != heights.end(); ++it) {
			while (!mono.empty() && !(*it > *mono.top())) {
				const auto target = mono.top(), firstLessOrEqualAfterTarget = it;
				mono.pop();
				const auto firstLessBeforeTarget = mono.top();

				const int h = *target;
				const int w = distance(firstLessBeforeTarget, firstLessOrEqualAfterTarget) - 1;
				ans = max(ans, w * h);
			}
			mono.push(it);
		}
		return ans;
	}
};
