class Solution {
public:
	/* time: O(numRows^2), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0)
			return {};
		vector<vector<int>> ans(numRows);
		ans[0].resize(1, 1);
		for (int n = 1; n < numRows; ++n) {
			ans[n].resize(n + 1);
			ans[n][0] = 1;
			for (int k = 1; k < n; ++k)
				ans[n][k] = ans[n - 1][k - 1] + ans[n - 1][k];
			ans[n][n] = 1;
		}
		return ans;
	}
};
