class Solution {
private:
	void transpose(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int y = 0; y < n; ++y)
			for (int x = y + 1; x < n; ++x)
				swap(matrix[y][x], matrix[x][y]);
	}
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());
		transpose(matrix);
	}
};
