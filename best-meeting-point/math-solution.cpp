class Solution {
private:
	template <class T, class F>
	static void inorderVisitY(const T& A, F visit) {
		for (int row = 0; row < A.size(); ++row) {
			for (int col = 0; col < A.front().size(); ++col) {
				if (A[row][col])
					visit(row);
			}
		}
	}
	template <class T, class F>
	static void inorderVisitX(const T& A, F visit) {
		for (int col = 0; col < A.front().size(); ++col) {
			for (int row = 0; row < A.size(); ++row) {
				if (A[row][col])
					visit(col);
			}
		}
	}
public:
	/* time: O(m*n), space: O(1) */
	static int minTotalDistance(const vector<vector<int>>& grid) {
		int k = 0;
		inorderVisitY(grid, [&](int y) { ++k; });

		int yRank = 0, medianY;
		inorderVisitY(grid, [&](int y) { if (yRank++ == k / 2) medianY = y; });

		int xRank = 0, medianX;
		inorderVisitX(grid, [&](int x) { if (xRank++ == k / 2) medianX = x; });

		int ans = 0;
		inorderVisitY(grid, [&](int y) { ans += abs(y - medianY); });
		inorderVisitX(grid, [&](int x) { ans += abs(x - medianX); });
		return ans;
	}
};
