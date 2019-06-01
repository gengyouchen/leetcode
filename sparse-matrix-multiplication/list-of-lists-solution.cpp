class Solution {
public:
	/* time: O(m*n*p), space: O(n*p) auxiliary (i.e. does not count output itself) */
	static vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
		const int m = A.size(), n = B.size(), p = B[0].size();
		vector<vector<pair<int, int>>> LIL(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < p; ++j) {
				if (B[i][j])
					LIL[i].emplace_back(j, B[i][j]);
			}
		}

		vector<vector<int>> ans(m, vector<int>(p));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (A[i][j]) {
					for (const auto& col : LIL[j])
						ans[i][col.first] += A[i][j] * col.second;
				}
			}
		}
		return ans;
	}
};
