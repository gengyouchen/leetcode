class Solution {
public:
	/* time: O(len(s)), space: O(1) */
	int titleToNumber(const string& s) {
		int ans = 0;
		for (char c : s)
			ans = ans * 26 + 1 + (c - 'A');
		return ans;
	}
};
