class Solution {
private:
	typedef vector<int>::iterator I;
public:
	/* time: O(m*n), space: O(n), where m = # of rows, n = # of cols */
	int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();

		/* See LeetCode 84 - Largest Rectangle in Histogram */
		vector<int> heights(n + 2, 0);
		heights[0] = -1, heights[n + 1] = 0;
		auto largestRectangleArea = [&]() {
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
		};

		int ans = 0;
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col)
				if (matrix[row][col] == '1')
					++heights[col + 1];
				else
					heights[col + 1] = 0;
			ans = max(ans, largestRectangleArea());
		}
		return ans;
	}
};
