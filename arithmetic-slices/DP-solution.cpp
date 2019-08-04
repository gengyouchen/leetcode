class Solution {
public:
	/* time: O(n), space: O(1) */
	static int numberOfArithmeticSlices(const vector<int>& A) {
		const int n = A.size();
		int ans = 0;

		int _dp;
#define DP(i) _dp
		for (int i = 0; i < n; ++i) {
			if (i >= 2 && A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				DP(i) = 1 + DP(i - 1);
			else
				DP(i) = 0;
			ans += DP(i);
		}
#undef DP
		return ans;
	}
};
