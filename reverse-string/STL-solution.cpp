class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static void reverseString(vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};
