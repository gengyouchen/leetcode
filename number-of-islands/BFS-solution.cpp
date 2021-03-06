class Solution {
public:
	/* time: O(m*n), space: O(m*n) */
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		const int m = grid.size(), n = grid[0].size();
		const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		auto select = [&](int row, int col, char selected) {
			const char target = grid[row][col];
			queue<pair<int, int>> Q;
			grid[row][col] = selected, Q.emplace(row, col);
			while (!Q.empty()) {
				row = Q.front().first, col = Q.front().second, Q.pop();
				for (const auto& dir : dirs) {
					const int y = row + dir[0], x = col + dir[1];
					if ((y >= 0) && (y < m) && (x >= 0) && (x < n) && (grid[y][x] == target))
						grid[y][x] = selected, Q.emplace(y, x);
				}
			}
		};
		int ans = 0;
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if (grid[row][col] == '1')
					select(row, col, '0'), ++ans;
			}
		}
		return ans;
	}
};
