/*
 * This backtracking solution is based on Constraint Propagation,
 * and is inspired by Peter Norvig, Director of Research in Google.
 *
 * For explanations, see his webpage: http://norvig.com/sudoku.html
 */
static array<unordered_set<int>, 81> cell2groups;
static array<unordered_set<int>, 27> group2cells;
static array<unordered_set<int>, 81> cell2peers;
static bool inited = [&]() {
	for (int cell = 0; cell < 81; ++cell) {
		const int row = cell / 9, col = cell % 9;
		for (int group : {row, 9 + col, 18 + (row / 3) * 3 + (col / 3)}) {
			cell2groups[cell].insert(group);
			group2cells[group].insert(cell);
		}
	}
	for (int cell = 0; cell < 81; ++cell)
		for (int group : cell2groups[cell])
			for (int peer : group2cells[group])
				if (peer != cell)
					cell2peers[cell].insert(peer);
	return true;
}();
class Sudoku {
private:
	array<bitset<9>, 81> choices;
public:
	Sudoku() {
		for (int cell = 0; cell < 81; ++cell)
			choices[cell].set();
	}
	bool isSolved() const {
		for (int cell = 0; cell < 81; ++cell)
			if (choices[cell].count() != 1)
				return false;
		return true;
	}
	int getAnswer(int cell) const {
		if (choices[cell].count() == 1)
			for (int num = 1; num <= 9; ++num)
				if (choices[cell].test(num - 1))
					return num;
		return -1;
	}
	int findCellWithFewestChoices() const {
		int ans = -1, fewest = INT_MAX;
		for (int cell = 0; cell < 81; ++cell) {
			const int nChoices = choices[cell].count();
			if (nChoices > 1 && nChoices < fewest)
				fewest = nChoices, ans = cell;
		}
		return ans;
	}
private:
	bool eliminate(int cell, int num) {
		if (!choices[cell].test(num - 1))
			return true;
		choices[cell].reset(num - 1);
		/*
		 * (1) If a cell has only one choice,
		 *     then eliminate that choice from all its peers.
		 */
		if (choices[cell].none())
			return false;
		if (choices[cell].count() == 1) {
			const int ans = getAnswer(cell);
			for (int peer : cell2peers[cell])
				if (!eliminate(peer, ans))
					return false;
		}
		/*
		 * (2) If a group has only one possible place for that number,
		 *     then assign that number there.
		 */
		for (int group : cell2groups[cell]) {
			int nPlaces = 0, lastPlace = -1;
			for (int place : group2cells[group])
				if (choices[place].test(num - 1))
					lastPlace = place, ++nPlaces;
			if (nPlaces == 0)
				return false;
			if (nPlaces == 1 && !assign(lastPlace, num))
				return false;
		}
		return true;
	}
public:
	bool assign(int cell, int num) {
		for (int i = 1; i <= 9; ++i)
			if (i != num && !eliminate(cell, i))
				return false;
		return true;
	}
};
class Solution {
private:
	bool backtrack(Sudoku& problem) {
		if (problem.isSolved())
			return true;
		/*
		 * Use MRV (Minimum Remaining Values) heuristic
		 * to decide which cell should be filled next
		 */
		int cell = problem.findCellWithFewestChoices();
		if (cell == -1)
			return false;
		for (int num = 1; num <= 9; ++num) {
			Sudoku tmp = problem;
			if (tmp.assign(cell, num) && backtrack(tmp)) {
				problem = tmp;
				return true;
			}
		}
		return false;
	}
public:
	/* time: O(9 ^ (# of undecided cells)), space: O(n) */
	void solveSudoku(vector<vector<char>>& board) {
		Sudoku problem;
		for (int row = 0; row < 9; ++row)
			for (int col = 0; col < 9; ++col)
				if (isdigit(board[row][col]))
					problem.assign(row * 9 + col, board[row][col] - '0');
		if (backtrack(problem))
			for (int row = 0; row < 9; ++row)
				for (int col = 0; col < 9; ++col)
					board[row][col] = problem.getAnswer(row * 9 + col) + '0';
	}
};
