class Solution {
public:
	/* time: O(numRows^2), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans(numRows);
		for (int n = 0; n < numRows; ++n) {
			ans[n].resize(n + 1);
			ans[n][0] = 1;
			/*
			 * Use recursive relationship: C(n,k) = C(n,k-1) * (n-k+1)/k
			 * Starting from C(n,0) = 1,
			 * iteratively calculate C(n,1), C(n,2), C(n,3), ..., C(n,n)
			 */
			for (int k = 1; k <= n; ++k)
				ans[n][k] = (long)ans[n][k - 1] * (n - k + 1) / k;
		}
		return ans;
	}
};
