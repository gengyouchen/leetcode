class Solution {
private:
	/* See LeetCode 84 - Largest Rectangle in Histogram */
	static int largestRectangleArea(const vector<int>& heights) {
		/*
		 * We guarantee the last number in heights array is 0,
		 * so there's no need to add heights.push_back(0) here
		 */
		const int n = heights.size();
		int area = 0;
		stack<int> mono;
		for (int R = 0; R < n; ++R) {
			while (!mono.empty() && heights[mono.top()] >= heights[R]) {
				const int h = heights[mono.top()];
				mono.pop();
				const int L = mono.empty() ? -1 : mono.top();
				area = max(area, h * (R - L - 1));
			}
			mono.push(R);
		}
		return area;
	}
public:
	/* time: O(m*n), space: O(n), where m = # of rows, n = # of cols */
	static int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();

		int ans = 0;
		vector<int> heights(n + 1);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1')
					++heights[j];
				else
					heights[j] = 0;
			}
			ans = max(ans, largestRectangleArea(heights));
		}
		return ans;
	}
};
