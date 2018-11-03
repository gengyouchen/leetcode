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
	/* time: O(log(m * n)) or O(log(m) + log(n)), space: O(1) */
	bool searchMatrix(const vector<vector<int>>& matrix, int target) {
		const int m = matrix.size();
		if (m == 0)
			return false;
		const int n = matrix[0].size();
		if (n == 0)
			return false;

		const int idx = lowestTrue(0, m * n - 1, [&](int i) {
			return matrix[i / n][i % n] >= target;
		});
		return matrix[idx / n][idx % n] == target;
	}
};
