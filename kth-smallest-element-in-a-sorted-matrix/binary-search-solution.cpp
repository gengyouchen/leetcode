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
public:
	/* time: O(n * log(max(matrix) - min(matrix))), space: O(1) */
	int kthSmallest(const vector<vector<int>>& matrix, int k) {
		const int n = matrix.size(), min = matrix[0][0], max = matrix[n - 1][n - 1];
		auto countLessEqual = [&](int target) {
			/* Saddleback Search */
			const int L = 0, D = n - 1;
			int R = n - 1, ans = 0;
			for (int U = 0; U <= D; ++U) {
				while (R >= L && !(matrix[U][R] <= target))
					--R;
				if (R < L)
					break;
				ans += R + 1;
			}
			return ans;
		};
		return lowestTrue(min, max, [&](int i) { return countLessEqual(i) >= k; });
	}
};
