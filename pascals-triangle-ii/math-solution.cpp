class Solution {
public:
	/* time: O(rowIndex), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<int> getRow(int rowIndex) {
		vector<int> ans(rowIndex + 1);
		ans[0] = 1;
		/*
		 * Use recursive relationship: C(n,k) = C(n,k-1) * (n-k+1)/k
		 * Starting from C(n,0) = 1,
		 * iteratively calculate C(n,1), C(n,2), C(n,3), ..., C(n,n)
		 */
		for (int i = 1; i <= rowIndex; ++i)
			ans[i] = (long)ans[i - 1] * (rowIndex - i + 1) / i;
		return ans;
	}
};
