class Solution {
public:
	/* time: O(n), space: O(range(char)) */
	int lengthOfLongestSubstring(const string& s) {
		bool appeared[256] = {};
		int ans = 0, L = 0;
		for (int R = 0; R < s.size(); ++R) {
			while (appeared[(unsigned char)s[R]])
				appeared[(unsigned char)s[L++]] = false;
			appeared[(unsigned char)s[R]] = true;
			ans = max(ans, R - L + 1);
		}
		return ans;
	}
};
