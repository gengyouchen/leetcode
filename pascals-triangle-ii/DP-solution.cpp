class Solution {
public:
	/* time: O(rowIndex^2), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<int> getRow(int rowIndex) {
		vector<int> ans(rowIndex + 1);
		ans[0] = 1;
		for (int n = 1; n <= rowIndex; ++n) {
			ans[n] = 1;
			for (int k = n - 1; k >= 1; --k)
				ans[k] = ans[k - 1] + ans[k];
			ans[0] = 1;
		}
		return ans;
	}
};
