class Solution {
public:
	/* time: O(m*n), space: O(m*n) */
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		const int m = board.size(), n = board[0].size();
		const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		auto select = [&](int row, int col, char selected) {
			const char target = board[row][col];
			queue<pair<int, int>> S;
			board[row][col] = selected, S.emplace(row, col);
			while (!S.empty()) {
				row = S.front().first, col = S.front().second, S.pop();
				for (const auto& dir : dirs) {
					const int y = row + dir[0], x = col + dir[1];
					if ((y >= 0) && (y < m) && (x >= 0) && (x < n) && (board[y][x] == target))
						board[y][x] = selected, S.emplace(y, x);
				}
			}
		};
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if ((row == 0) || (row == m - 1) || (col == 0) || (col == n - 1)) {
					if (board[row][col] == 'O')
						select(row, col, 'S');
				}
			}
		}
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if (board[row][col] == 'O')
					board[row][col] = 'X';
				else if (board[row][col] == 'S')
					board[row][col] = 'O';
			}
		}
	}
};
