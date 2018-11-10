class Solution {
private:
	typedef function<bool(int, int, int)> F;
public:
	/*
	 * time: O((3^k)*m*n), space: O(k) auxiliary (i.e. does not count input itself),
	 * where m = # of rows, n = # of cols, k = len(word)
	 */
	bool exist(vector<vector<char>>& board, const string& word) {
		const int len = word.size(), m = board.size(), n = board[0].size();
		if (len == 0)
			return true;

		F backtrack = [&](int row, int col, int step) {
			if ((row < 0) || (row >= m) || (col < 0) || (col >= n))
				return false;

			const char c = board[row][col];
			if (c == '*' || word[step] != c)
				return false;

			if (step == len - 1)
				return true;
			board[row][col] = '*';

			bool found = false;
			if (!found)
				found = backtrack(row + 1, col, step + 1);
			if (!found)
				found = backtrack(row - 1, col, step + 1);
			if (!found)
				found = backtrack(row, col + 1, step + 1);
			if (!found)
				found = backtrack(row, col - 1, step + 1);

			board[row][col] = c;
			return found;
		};

		for (int row = 0; row < m; ++row)
			for (int col = 0; col < n; ++col)
				if (backtrack(row, col, 0))
					return true;
		return false;
	}
};
