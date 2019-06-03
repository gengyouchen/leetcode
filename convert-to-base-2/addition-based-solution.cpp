class Solution {
public:
	/* time: O(log(N)), space: O(1) auxiliary (i.e. does not count output itself) */
	static string baseNeg2(int N) {
		string ans;
		int carry = 0;
		while (N || carry) {
			int val = carry;
			if (ans.size() % 2)
				val -= N % 2, N /= 2;
			else
				val += N % 2, N /= 2;
			switch (val) {
			case -2:
				carry = 1, val = 0;
				break;
			case -1:
				carry = 1, val = 1;
				break;
			case 0:
				carry = 0, val = 0;
				break;
			case 1:
				carry = 0, val = 1;
				break;
			case 2:
				carry = -1, val = 0;
				break;
			}
			ans.push_back('0' + val);
		}
		while (ans.size() > 1 && ans.back() == '0')
			ans.pop_back();
		reverse(ans.begin(), ans.end());
		return ans.empty() ? "0" : ans;
	}
};
