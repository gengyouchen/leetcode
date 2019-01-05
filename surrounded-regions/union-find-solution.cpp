class DisjointSet {
private:
	vector<int> p, rank;
public:
	DisjointSet(int n) : p(n), rank(n, 0) {
		iota(p.begin(), p.end(), 0);
	}
	int FindSet(int x) {
		if (p[x] != x)
			p[x] = FindSet(p[x]);
		return p[x];
	}
	void Union(int x, int y) {
		x = FindSet(x), y = FindSet(y);
		if (rank[x] > rank[y])
			p[y] = x;
		else {
			p[x] = y;
			if (rank[x] == rank[y])
				++rank[y];
		}
	}
};

class Solution {
public:
	/*
	 * time: O(m*n * alpha(m*n)) ~= O(m*n), space: O(m*n),
	 * where alpha(x) is the inverse Ackermann function.
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		const int m = board.size(), n = board[0].size();

		DisjointSet s(m * n + 1);
		const int dummy = m * n;

		const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if (board[row][col] == 'O') {
					if ((row == 0 || row == m - 1 || col == 0 || col == n - 1))
						s.Union(row * n + col, dummy);
					for (const auto& dir : dirs) {
						const int y = row + dir[0], x = col + dir[1];
						if ((y >= 0) && (y < m) && (x >= 0) && (x < n) && (board[y][x] == 'O'))
							s.Union(y * n + x, row * n + col);
					}
				}
			}
		}
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if ((board[row][col] == 'O') && (s.FindSet(row * n + col) != s.FindSet(dummy)))
					board[row][col] = 'X';
			}
		}
	}
};
