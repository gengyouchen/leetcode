class Solution {
private:
	template <class T, class F>
	T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
	bool hsearch(const vector<vector<int>>& A, int target, int U, int L, int D, int R) {
		if (L > R || U > D || target < A[U][L] || target > A[D][R])
			return false;
		const int mid = (D + U) / 2;
		const int col = lowestTrue(L, R + 1, [&](int i) { return A[mid][i] >= target; });
		if (col != R + 1 && A[mid][col] == target)
			return true;
		return hsearch(A, target, mid + 1, L, D, col - 1) || hsearch(A, target, U, col, mid - 1, R);
	}
	bool vsearch(const vector<vector<int>>& A, int target, int U, int L, int D, int R) {
		if (L > R || U > D || target < A[U][L] || target > A[D][R])
			return false;
		const int mid = (L + R) / 2;
		const int row = lowestTrue(U, D + 1, [&](int i) { return A[i][mid] >= target; });
		if (row != D + 1 && A[row][mid] == target)
			return true;
		return vsearch(A, target, U, mid + 1, row - 1, R) || vsearch(A, target, row, L, D, mid - 1);
	}
public:
	/*
	 * time: O(m * (1 + log(n) - log(m))), space: O(log(m, n)),
	 * where m = min(nRow, nCol), n = max(nRow, nCol)
	 *
	 * <Proof>
	 * In average case,
	 * we assume each partition point is at the center of the partition row.
	 *
	 * For a m-row * n-col matrix, assuming m < n without losing generality
	 * T(m, n) = 2*T(m/2, n/2) + c*log(n)
	 *         = T(1, n/m) + c*sum{2^k * log(n / 2^k)}
	 *         = T(1, n/m) + c*sum{2^k * (log(n) - log(2^k))}
	 *         = T(1, n/m) + c*sum{2^k * (log(n) - k)}
	 *         = T(1, n/m) + c*(log(n)*sum{2^k} - sum{k * 2^k})
	 *         where 0 <= k <= log(m)
	 *
	 * To calculate sum{2^k} and sum{k * 2^k}, use the Geometric Progression's formulas
	 * (see https://en.wikipedia.org/wiki/Geometric_progression#Related_formulas)
	 * sum{2^k} = (1 - 2^(log(m)+1)) / (1 - 2) = 2*m - 1
	 * sum{k * 2^k} = 2*sum{k * 2^(k-1)}
	 *              = 2*((1 - 2^(log(m)+1)) / (1-2)^2 - (log(m)+1) * 2^(log(m)) / (1-2))
	 *              = 2*((1 - 2*m) + (log(m)+1) * m)
	 *              = 2*(1 - m + m*log(m))
	 *
	 * Therefore,
	 * T(m, n) = T(1, n/m) + c*(log(n)*sum{2^k} - sum{k * 2^k})
	 *         = T(1, n/m) + c*(log(n)*(2*m - 1) - 2*(1 - m + m*log(m)))
	 *         = T(1, n/m) + c*(2*m + 2*m*(log(n) - log(m)) - log(n) - 2)
	 *         = O(m * (1 + log(n) - log(m)))
	 */
	bool searchMatrix(const vector<vector<int>>& matrix, int target) {
		const int m = matrix.size();
		if (m == 0)
			return false;
		const int n = matrix[0].size();
		if (n == 0)
			return false;
		if (m < n)
			return hsearch(matrix, target, 0, 0, m - 1, n - 1);
		else
			return vsearch(matrix, target, 0, 0, m - 1, n - 1);
	}
};
