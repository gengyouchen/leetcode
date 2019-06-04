class Solution {
private:
	typedef vector<int> V1D;
	typedef vector<V1D> V2D;
public:
	/* time: O(m*n*k), space: O(m*n), where k = # of buildings */
	static int shortestDistance(vector<vector<int>>& grid) {
		if (grid.empty())
			return -1;
		const int m = grid.size(), n = grid[0].size();
		V2D totalDistance(m, V1D(n)), nReached(m, V1D(n));

		const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		int empty = 0;
		auto bfs = [&](int y0, int x0) {
			queue<pair<int, int>> q;
			q.emplace(y0, x0);
			for (int d = 0; !q.empty(); ++d) {
				for (int i = q.size(); i > 0; --i) {
					const int row = q.front().first, col = q.front().second;
					q.pop(), ++nReached[row][col], totalDistance[row][col] += d;
					for (const auto& dir : dirs) {
						const int y = row + dir[0], x = col + dir[1];
						if (y >= 0 && y < m && x >= 0 && x < n && grid[y][x] == empty)
							q.emplace(y, x), --grid[y][x];
					}
				}
			}
			--empty;
		};

		int nBuilding = 0;
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if (grid[row][col] == 1)
					++nBuilding, bfs(row, col);
			}
		}

		int ans = INT_MAX;
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if (grid[row][col] == empty && nReached[row][col] == nBuilding)
					ans = min(ans, totalDistance[row][col]);
			}
		}
		return (ans == INT_MAX) ? -1 : ans;
	}
};
