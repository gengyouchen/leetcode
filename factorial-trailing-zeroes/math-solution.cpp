class Solution {
public:
	/* time: O(log(n)), space: O(1) */
	int trailingZeroes(int n) {
		int ans = 0;
		for (long i = 5; i <= n; i *= 5)
			ans += n / i;
		return ans;
	}
};
