class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void reverseWords(vector<char>& str) {
		reverse(str.begin(), str.end());

		auto L = str.begin(), R = str.begin();
		while (true) {
			L = find_if(R, str.end(), [](char c) { return c != ' '; });
			if (L == str.end())
				break;
			R = find_if(L, str.end(), [](char c) { return c == ' '; });
			reverse(L, R);
		}
	}
};
