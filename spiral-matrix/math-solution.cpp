class Solution {
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<int> spiralOrder(const vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty())
			return ans;
		int m = matrix.size(), n = matrix[0].size(), r0 = 0, c0 = 0, dir = 0;
		while (m > 0 && n > 0)
			switch (dir) {
			case 0:
				for (int i = 0; i < n; ++i)
					ans.push_back(matrix[r0][c0 + i]);
				--m, ++r0, ++dir;
				break;
			case 1:
				for (int i = 0; i < m; ++i)
					ans.push_back(matrix[r0 + i][c0 + n - 1]);
				--n, ++dir;
				break;
			case 2:
				for (int i = n - 1; i >= 0; --i)
					ans.push_back(matrix[r0 + m - 1][c0 + i]);
				--m, ++dir;
				break;
			default:
				for (int i = m - 1; i >= 0; --i)
					ans.push_back(matrix[r0 + i][c0]);
				--n, ++c0, dir = 0;
			}
		return ans;
	}
};
