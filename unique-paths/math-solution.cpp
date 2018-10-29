class Solution {
private:
	int C(int n, int k) {
		/*
		 * Use recursive relationship: C(i,k) = C(i-1,k) * i/(i-k)
		 * Starting from C(k,k) = 1,
		 * iteratively calculate C(k+1,k), C(k+2,k), C(k+3,k), ..., C(n,k)
		 */
		long ans = 1;
		for (int i = k + 1; i <= n; ++i)
			ans = ans * i / (i - k);
		return ans;
	}
public:
	/* time: O(min(m,n)), space: O(1) */
	int uniquePaths(int m, int n) {
		if (m < n)
			return uniquePaths(n, m);
		return C((m - 1) + (n - 1), (m - 1));
	}
};
