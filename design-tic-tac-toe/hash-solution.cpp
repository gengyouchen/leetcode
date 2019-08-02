class TicTacToe {
private:
	const int n;
	vector<vector<int>> groups;
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count hash table itself) */
	TicTacToe(int n) : n(n), groups(2, vector<int>(n * 2 + 2)) {}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count hash table itself) */
	int move(int row, int col, int player) {
		if (++groups[player - 1][row] == n)
			return player;
		if (++groups[player - 1][n + col] == n)
			return player;
		if (row == col && ++groups[player - 1][n * 2] == n)
			return player;
		if (row + col == n - 1 && ++groups[player - 1][n * 2 + 1] == n)
			return player;
		return 0;
	}
};
