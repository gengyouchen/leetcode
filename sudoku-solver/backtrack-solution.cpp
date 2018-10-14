/*
 * This backtracking solution is based on Constraint Propagation,
 * and is inspired by Peter Norvig, Director of Research in Google.
 *
 * For explanations, see his webpage: http://norvig.com/sudoku.html
 */
static array<unordered_set<int>, 81> cell2units;
static array<unordered_set<int>, 27> unit2cells;
static array<unordered_set<int>, 81> cell2peers;
static bool tableInited = [&]() {  
	for (int cell = 0; cell < 81; ++cell) {
		int row = cell / 9, col = cell % 9;
		auto units = {row, 9 + col, 18 + (row / 3) * 3 + (col / 3)};
		for (int unit : units) {
			cell2units[cell].insert(unit);
			unit2cells[unit].insert(cell);
		}
	}
	for (int cell = 0; cell < 81; ++cell)
		for (int unit : cell2units[cell])
			for (int peer : unit2cells[unit])
				if (peer != cell)
					cell2peers[cell].insert(peer);
	return true;
}();

class Choices {
private:
	bitset<9> bits;
public:
	Choices() : bits(0x3ff) { };
	bool is_on(int i) const { return bits.test(i - 1); }
	int count() const { return bits.count(); }
	void eliminate(int i) { bits.reset(i - 1); }
	int val() const {
		for (int i = 1; i <= 9; ++i)
			if (is_on(i))
				return i;
		return -1;
	}
};

class Sudoku {
private:
	array<Choices, 81> cell2choices;
	bool eliminate(int cell, int val) {
		if (!cell2choices[cell].is_on(val))
			return true; /* already eliminated */
		cell2choices[cell].eliminate(val);

		/*
		 * (1) If a cell has only one possible value,
		 *     then eliminate that value from the cell's peers.
		 */
		if (cell2choices[cell].count() == 0)
			return false;
		if (cell2choices[cell].count() == 1) {
			const int decided = cell2choices[cell].val();
			for (int peer : cell2peers[cell])
				if (!eliminate(peer, decided))
					return false;
		}

		/*
		 * (2) If a unit has only one possible place for a value,
		 *     then put the value there.
		 */
		for (int unit : cell2units[cell]) {
			int nCandidate = 0, lastCandidate = -1;
			for (int member : unit2cells[unit])
				if (cell2choices[member].is_on(val))
					lastCandidate = member, ++nCandidate;
			if (nCandidate == 0)
				return false;
			if (nCandidate == 1 && !assign(lastCandidate, val))
				return false;
		}
		return true;
	}
public:
	bool assign(int cell, int val) {
		for (int i = 1; i <= 9; ++i)
			if (i != val && !eliminate(cell, i))
				return false;
		return true;
	}
	int getAnswer(int cell) const {
		if (cell2choices[cell].count() != 1)
			return -1;
		return cell2choices[cell].val();
	}
	bool isSolved() const {
		for (int cell = 0; cell < 81; ++cell)
			if (cell2choices[cell].count() != 1)
				return false;
		return true;
	}
	int findCellWithMRV() const {
		/*
		 * Use MRV (Minimum Remaining Values) heuristic
		 * to decide which cell should be filled next
		 */
		int bestCell = -1, nChoices = INT_MAX;
		for (int cell = 0; cell < 81; ++cell) {
			const int n = cell2choices[cell].count();
			if (n > 1 && n < nChoices)
				bestCell = cell, nChoices = n;
		}
		return bestCell;
	}
};

class Solution {
private:
	bool solve(Sudoku& s) {
		if (s.isSolved())
			return true;
		int cell = s.findCellWithMRV();
		if (cell == -1)
			return false;
		for (int i = 1; i <= 9; i++) {
			Sudoku tmp = s;
			if (tmp.assign(cell, i) && solve(tmp)) {
				s = tmp;
				return true;
			}
		}
		return false;
	}
public:
	/* time: O(9 ^ (# of undecided cells)), space: O(n) */
	void solveSudoku(vector<vector<char>>& board) {
		Sudoku s;
		for (int row = 0; row < 9; ++row)
			for (int col = 0; col < 9; ++col)
				if (isdigit(board[row][col]))
					s.assign(row * 9 + col, board[row][col] - '0');
		if (!solve(s))
			return;
		for (int row = 0; row < 9; ++row)
			for (int col = 0; col < 9; ++col)
				board[row][col] = s.getAnswer(row * 9 + col) + '0';
	}
};
