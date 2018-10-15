class Solution {
private:
	typedef function<bool(int)> F;
public:
	/* time: O(9 ^ (# of undecided cells)), space: O(n) */
	void solveSudoku(vector<vector<char>>& board) {
		array<bitset<9>, 27> groups;
		auto assign = [&](int row, int col, int num) {
			for (int i : {row, 9 + col, 18 + (row / 3) * 3 + (col / 3)})
				if (groups[i].test(num - 1))
					return false; /* failed */
			for (int i : {row, 9 + col, 18 + (row / 3) * 3 + (col / 3)})
				groups[i].set(num - 1);
			board[row][col] = '0' + num;
			return true; /* succeed */
		};
		auto undo = [&](int row, int col) {
			const int num = board[row][col] - '0';
			for (int i : {row, 9 + col, 18 + (row / 3) * 3 + (col / 3)})
				groups[i].reset(num - 1);
			board[row][col] = '.';
		};
		F backtrack = [&](int step) {
			const int row = step / 9, col = step % 9;
			if (step == 81)
				return true;
			if (board[row][col] != '.')
				return backtrack(step + 1);
			for (int num = 1; num <= 9; ++num)
				if (assign(row, col, num)) {
					if (backtrack(step + 1))
						return true;
					undo(row, col);
				}
			return false;
		};
		for (int row = 0; row < 9; ++row)
			for (int col = 0; col < 9; ++col)
				if (board[row][col] != '.')
					assign(row, col, board[row][col] - '0');
		backtrack(0);
	}
};
