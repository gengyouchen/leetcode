class Solution {
public:
	/* time: O(n), space: O(n) */
	static int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		const int n = heights.size();

		int ans = 0;
		stack<int> mono;
		for (int R = 0; R < n; ++R) {
			while (!mono.empty() && heights[mono.top()] >= heights[R]) {
				const int h = heights[mono.top()];
				mono.pop();
				const int L = mono.empty() ? -1 : mono.top();
				ans = max(ans, h * (R - L - 1));
			}
			mono.push(R);
		}
		return ans;
	}
};
