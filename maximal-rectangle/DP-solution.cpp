class Solution {
public:
	/* time: O(m*n), space: O(n), where m = # of rows, n = # of cols */
	int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();

		vector<int> _height(n, 0), _firstLessBeforeTarget(n, -1), _firstLessAfterTarget(n, n);
		auto height = [&](int row, int target) -> int& { return _height[target]; };
		auto firstLessBeforeTarget = [&](int row, int target) -> int& { return _firstLessBeforeTarget[target]; };
		auto firstLessAfterTarget = [&](int row, int target) -> int& { return _firstLessAfterTarget[target]; };

		int ans = 0;
		for (int row = 0; row < m; ++row) {
			for (int target = 0; target < n; ++target)
				if (matrix[row][target] == '1')
					height(row, target) = height(row - 1, target) + 1;
				else
					height(row, target) = 0;

			for (int target = 0, firstZeroBeforeTarget = -1; target < n; ++target)
				if (matrix[row][target] == '1')
					firstLessBeforeTarget(row, target) = max(firstLessBeforeTarget(row - 1, target), firstZeroBeforeTarget);
				else
					firstLessBeforeTarget(row, target) = -1, firstZeroBeforeTarget = target;

			for (int target = n - 1, firstZeroAfterTarget = n; target >= 0; --target)
				if (matrix[row][target] == '1')
					firstLessAfterTarget(row, target) = min(firstLessAfterTarget(row - 1, target), firstZeroAfterTarget);
				else
					firstLessAfterTarget(row, target) = n, firstZeroAfterTarget = target;

			for (int target = 0; target < n; ++target) {
				const int h = height(row, target);
				const int w = firstLessAfterTarget(row, target) - firstLessBeforeTarget(row, target) - 1;
				ans = max(ans, h * w);
			}
		}
		return ans;
	}
};
