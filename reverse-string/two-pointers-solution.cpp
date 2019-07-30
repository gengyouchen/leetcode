class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static void reverseString(vector<char>& s) {
		const int n = s.size();
		int L = 0, R = n - 1;
		while (L < R)
			swap(s[L++], s[R--]);
	}
};
