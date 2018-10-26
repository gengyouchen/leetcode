class Solution {
private:
	typedef function<void(int)> F;
public:
	/* time: O(n!), space: O(n) */
	int totalNQueens(int n) {
		int ans = 0;
		vector<bool> groups(n * 5 - 2, false);
		auto assign = [&](int row, int col) {
			for (int i : {(n - 1) + (row - col), (n * 2 - 1) + (row + col), (n * 4 - 2) + col})
				if (groups[i])
					return false; /* failed */
			for (int i : {(n - 1) + (row - col), (n * 2 - 1) + (row + col), (n * 4 - 2) + col})
				groups[i] = true;
			return true; /* succeed */
		};
		auto undo = [&](int row, int col) {
			for (int i : {(n - 1) + (row - col), (n * 2 - 1) + (row + col), (n * 4 - 2) + col})
				groups[i] = false;
		};
		F backtrack = [&](int row) {
			if (row == n)
				++ans;
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
