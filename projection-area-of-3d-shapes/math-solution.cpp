class Solution {
public:
	/* time: O(n^2), space: O(1) */
	int projectionArea(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); ++i) {
			int maxCol = 0, maxRow = 0;
			for (int j = 0; j < grid.size(); ++j) {
				maxCol = max(maxCol, grid[i][j]);
				maxRow = max(maxRow, grid[j][i]);
				if (grid[i][j])
					++ans;
			}
			ans += maxCol + maxRow;
		}
		return ans;
	}
};
