class RangeMinimumQuery {
private:
	const vector<int>& A;
	vector<vector<int>> sparseTable;
public:
	RangeMinimumQuery(const vector<int>& A) : A(A) {
		const int n = A.size();
		sparseTable.emplace_back(n);
		iota(sparseTable[0].begin(), sparseTable[0].end(), 0);

		for (int row = 1, len = 2; len <= n; ++row, len *= 2) {
			const int nColumns = n - len + 1;
			sparseTable.emplace_back(nColumns);
			for (int i = 0; i < nColumns; ++i) {
				const int L = sparseTable[row - 1][i];
				const int R = sparseTable[row - 1][i + len / 2];
				sparseTable[row][i] = (A[L] < A[R]) ? L : R;
			}
		}
	}
	int query(int i, int j) const {
		const int row = ilogb(j - i + 1), len = (1 << row);
		const int L = sparseTable[row][i];
		const int R = sparseTable[row][j - len + 1];
		return (A[L] < A[R]) ? L : R;
	}
};

class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	static int largestRectangleArea(const vector<int>& heights) {
		const int n = heights.size();
		const RangeMinimumQuery rmq(heights);

		int ans = 0;
		using F = function<void(int, int)>;
		F dfs = [&](int i, int j) {
			if (i <= j) {
				const int pivot = rmq.query(i, j);
				ans = max(ans, heights[pivot] * (j - i + 1));
				dfs(i, pivot - 1), dfs(pivot + 1, j);
			}
		};
		dfs(0, n - 1);
		return ans;
	}
};
