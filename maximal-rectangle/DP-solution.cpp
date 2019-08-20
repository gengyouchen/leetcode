class Solution {
public:
	/* time: O(m*n), space: O(n), where m = # of rows, n = # of cols */
	static int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();

		int ans = 0;
		vector<int> height(n), bestL(n, -1), bestR(n, n);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1')
					++height[j];
				else
					height[j] = 0 /* reset height */;
			}

			for (int j = 0, currL = -1; j < n; ++j) {
				if (matrix[i][j] == '1')
					bestL[j] = max(bestL[j], currL);
				else
					bestL[j] = -1 /* reset bestL */, currL = j;
			}

			for (int j = n - 1, currR = n; j >= 0; --j) {
				if (matrix[i][j] == '1')
					bestR[j] = min(bestR[j], currR);
				else
					bestR[j] = n /* reset bestR */, currR = j;
			}

			for (int j = 0; j < n; ++j)
				ans = max(ans, height[j] * (bestR[j] - bestL[j] - 1));
		}
		return ans;
	}
};
