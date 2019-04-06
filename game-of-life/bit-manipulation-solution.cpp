class Solution {
public:
	/* time: O(m*n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static void gameOfLife(vector<vector<int>>& board) {
		if (board.empty())
			return;

		const int m = board.size(), n = board[0].size();
		const vector<vector<int>> D = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				int nNeighbors = 0;
				for (const auto& d : D) {
					const int y = row + d[0], x = col + d[1];
					if ((y >= 0) && (y < m) && (x >= 0) && (x < n) && (board[y][x] & 1))
						++nNeighbors;
				}
				if (board[row][col] & 1) {
					if (nNeighbors == 2 || nNeighbors == 3)
						board[row][col] |= 2;
				} else {
					if (nNeighbors == 3)
						board[row][col] |= 2;
				}
			}
		}
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col)
				board[row][col] >>= 1;
		}
	}
};
