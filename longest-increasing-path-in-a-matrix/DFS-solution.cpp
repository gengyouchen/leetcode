class Solution {
public:
	/* time: O(m*n), space: O(m*n) */
	static int longestIncreasingPath(const vector<vector<int>>& matrix) {
		if (matrix.empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();
		const vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		vector<vector<int>> h(m, vector<int>(n));

		using F = function<int(int, int)>;
		F dfs = [&](int y, int x) {
			if (h[y][x])
				return h[y][x];

			h[y][x] = 1;
			for (const auto& dir : dirs) {
				const int y1 = y + dir.first, x1 = x + dir.second;
				if (y1 >= 0 && y1 < m && x1 >= 0 && x1 < n && matrix[y1][x1] > matrix[y][x])
					h[y][x] = max(h[y][x], 1 + dfs(y1, x1));
			}
			return h[y][x];
		};

		int ans = 0;
		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x)
				ans = max(ans, dfs(y, x));
		}
		return ans;
	}
};
