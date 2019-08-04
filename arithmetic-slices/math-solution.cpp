class Solution {
public:
	/* time: O(n), space: O(1) */
	static int numberOfArithmeticSlices(const vector<int>& A) {
		const int n = A.size();
		int ans = 0;

		int len = 0;
		for (int i = 2; i < n; ++i) {
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				++len;
			else
				ans += (1 + len) * len / 2, len = 0;
		}
		ans += (1 + len) * len / 2;
		return ans;
	}
};
