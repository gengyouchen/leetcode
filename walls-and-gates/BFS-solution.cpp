class Solution {
public:
	/* time: O(m*n), space: O(m*n) */
	static void wallsAndGates(vector<vector<int>>& rooms) {
		if (rooms.empty())
			return;

		const int m = rooms.size(), n = rooms[0].size();
		queue<int> Q;
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				const int position = row * n + col;
				if (rooms[row][col] == 0)
					Q.push(position);
			}
		}

		auto discover = [&](int row, int col, int distance) {
			if (row < 0 || row >= m || col < 0 || col >= n)
				return;
			const int position = row * n + col;
			if (rooms[row][col] == INT_MAX)
				rooms[row][col] = distance, Q.push(position);
		};

		for (int depth = 1; !Q.empty(); ++depth) {
			for (int i = Q.size(); i > 0; --i) {
				const int u = Q.front();
				Q.pop();
				const int row = u / n, col = u % n;
				discover(row - 1, col, depth);
				discover(row + 1, col, depth);
				discover(row, col - 1, depth);
				discover(row, col + 1, depth);
			}
		}
	}
};
