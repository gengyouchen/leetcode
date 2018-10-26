class Solution {
private:
	typedef function<void(int)> F;
public:
	/* time: O(n!), space: O(n^2) auxiliary (i.e. does not count output itself) */
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ans;
		vector<string> board(n, string(n, '.'));
		vector<bool> groups(n * 5 - 2, false);
		auto assign = [&](int row, int col) {
			for (int i : {(n - 1) + (row - col), (n * 2 - 1) + (row + col), (n * 4 - 2) + col})
				if (groups[i])
					return false; /* failed */
			for (int i : {(n - 1) + (row - col), (n * 2 - 1) + (row + col), (n * 4 - 2) + col})
				groups[i] = true;
			board[row][col] = 'Q';
			return true; /* succeed */
		};
		auto undo = [&](int row, int col) {
			for (int i : {(n - 1) + (row - col), (n * 2 - 1) + (row + col), (n * 4 - 2) + col})
				groups[i] = false;
			board[row][col] = '.';
		};
		F backtrack = [&](int row) {
			if (row == n)
				ans.push_back(board);
			else
				for (int col = 0; col < n; ++col)
					if (assign(row, col)) {
						backtrack(row + 1);
						undo(row, col);
					}
		};
		backtrack(0);
		return ans;
	}
};
