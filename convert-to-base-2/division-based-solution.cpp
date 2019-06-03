class Solution {
public:
	/* time: O(log(N)), space: O(1) auxiliary (i.e. does not count output itself) */
	static string baseNeg2(int N) {
		string ans;
		while (N) {
			const int bit = N & 1;
			ans.push_back('0' + bit), N = (N - bit) / -2;
		}
		reverse(ans.begin(), ans.end());
		return ans.empty() ? "0" : ans;
	}
};
