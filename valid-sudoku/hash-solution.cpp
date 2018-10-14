class Solution {
public:
	/* time: O(1), space: O(1) */
	bool isValidSudoku(vector<vector<char>>& board) {
		array<bitset<9>, 27> groups;
		for (int row = 0; row < 9; ++row)
			for (int col = 0; col < 9; ++col)
				if (board[row][col] != '.')
					for (int i : {row, 9 + col, 18 + (row / 3) * 3 + (col / 3)}) {
						const int num = board[row][col] - '0';
						if (groups[i].test(num - 1))
							return false;
						groups[i].set(num - 1);
					}
		return true;
	}
};
