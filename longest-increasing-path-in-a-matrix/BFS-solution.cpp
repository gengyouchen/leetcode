class Solution {
public:
	/* time: O(m*n), space: O(m*n), where m = # of rows, n = # of columns */
	static int longestIncreasingPath(const vector<vector<int>>& matrix) {
		if (matrix.empty())
			return 0;
		const int m = matrix.size(), n = matrix[0].size();
		const vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

		queue<pair<int, int>> Q;
		vector<vector<int>> nInDegree(m, vector<int>(n));
		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				for (const auto& dir : dirs) {
					const int y1 = y + dir.first, x1 = x + dir.second;
					if (y1 >= 0 && y1 < m && x1 >= 0 && x1 < n && matrix[y1][x1] < matrix[y][x])
						++nInDegree[y][x];
				}
				if (!nInDegree[y][x])
					Q.emplace(y, x);
			}
		}

		int ans = 0;
		for (int depth = 1; !Q.empty(); ++depth) {
			for (int len = Q.size(); len > 0; --len) {
				const int y = Q.front().first, x = Q.front().second;
				Q.pop();
				for (const auto& dir : dirs) {
					const int y1 = y + dir.first, x1 = x + dir.second;
					if (y1 >= 0 && y1 < m && x1 >= 0 && x1 < n && matrix[y1][x1] > matrix[y][x]) {
						if (!--nInDegree[y1][x1])
							Q.emplace(y1, x1);
					}
				}
			}
			++ans;
		}
		return ans;
	}
};
