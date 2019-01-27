class Solution {
public:
	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count output itself) */
	string convertToTitle(int n) {
		string ans;
		while (n > 0) {
			if (n % 26)
				ans.push_back('A' + (n % 26 - 1));
			else
				ans.push_back('Z'), n -= 26;
			n /= 26;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
