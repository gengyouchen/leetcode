class Solution {
public:
	/* time: O(log(n)), space: O(1) */
	int countDigitOne(int n) {
		int ans = 0;
		for (long base = 1; base <= n; base *= 10)
			ans += n / (base * 10) * base + min(max(n % (base * 10) - base + 1, 0L), base);
		return ans;
	}
};
