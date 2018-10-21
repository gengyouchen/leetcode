class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int L = n, x0 = 0, y0 = 0; L > 1; L -= 2, ++x0, ++y0)
			for (int i = 0; i < L - 1; ++i) {
				int& num0 = matrix[y0][x0 + i];
				int& num1 = matrix[y0 + i][x0 + (L - 1)];
				int& num2 = matrix[y0 + (L - 1)][x0 + (L - 1) - i];
				int& num3 = matrix[y0 + (L - 1) - i][x0];
				const int tmp = num0;
				num0 = num3, num3 = num2, num2 = num1, num1 = tmp;
			}
	}
};
