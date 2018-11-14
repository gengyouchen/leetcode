class Solution {
private:
	typedef vector<int>::iterator I;
	/* See LeetCode 84 - Largest Rectangle in Histogram */
	int largestRectangleArea(vector<int> heights) {
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
public:
	/* time: O(m*n), space: O(n), where m = # of rows, n = # of cols */
	int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();

		int ans = 0;
		vector<int> histogram(n, 0);
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col)
				if (matrix[row][col] == '1')
					histogram[col]++;
				else
					histogram[col] = 0;
			ans = max(ans, largestRectangleArea(histogram));
		}
		return ans;
	}
};
