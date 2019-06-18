class Solution {
public:
	/* time: O(m*n), space: O(m*n) */
	static int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		const int m = grid.size(), n = grid[0].size();
		const vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

		queue<pair<int, int>> Q;
		if (grid[0][0] == 0)
			Q.emplace(0, 0), grid[0][0] = 1;

		for (int depth = 1; !Q.empty(); ++depth) {
			for (int i = Q.size(); i > 0; --i) {
				const int y = Q.front().first, x = Q.front().second;
				Q.pop();
				if (y == m - 1 && x == n - 1)
					return depth;
				for (const auto& dir : dirs) {
					const int y1 = y + dir.first, x1 = x + dir.second;
					if (y1 >= 0 && y1 < m && x1 >= 0 && x1 < n && !grid[y1][x1])
						Q.emplace(y1, x1), grid[y1][x1] = 1;
				}
			}
		}
		return -1;
	}
};
