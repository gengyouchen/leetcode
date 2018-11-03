class Solution {
public:
	/* time: O(m+n), space: O(1) */
	bool searchMatrix(const vector<vector<int>>& matrix, int target) {
		const int m = matrix.size();
		if (m == 0)
			return false;
		const int n = matrix[0].size();
		if (n == 0)
			return false;

		/* Saddleback Search */
		const int L = 0, D = m - 1;
		int R = n - 1;
		for (int U = 0; U <= D; ++U) {
			while (R >= L && !(matrix[U][R] <= target))
				--R;
			if (R < L)
				return false;
			if (matrix[U][R] == target)
				return true;
		}
		return false;
	}
};
