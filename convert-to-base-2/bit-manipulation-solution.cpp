class Solution {
public:
	/* time: O(log(N)), space: O(1) auxiliary (i.e. does not count output itself) */
	static string baseNeg2(int N) {
		/*
		 * At each odd bit, if its value is 1, we should produce a carry
		 * This is because the odd position means -1, not 1
		 * Therefore, a carry is needed such that -1 + 2 = 1
		 */
		N = (N + 0xAAAAAAAA) ^ 0xAAAAAAAA;

		string ans;
		while (N)
			ans.push_back('0' + N % 2), N /= 2;
		reverse(ans.begin(), ans.end());
		return ans.empty() ? "0" : ans;
	}
};
