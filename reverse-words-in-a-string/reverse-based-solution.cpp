class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void reverseWords(string &s) {
		reverse(s.begin(), s.end());

		auto L = s.begin(), R = s.begin(), out = s.begin();
		while (true) {
			L = find_if(R, s.end(), [](char c) { return c != ' '; });
			if (L == s.end())
				break;
			R = find_if(L, s.end(), [](char c) { return c == ' '; });

			if (out != s.begin())
				*out++ = ' ';
			reverse(L, R), copy(L, R, out), out += distance(L, R);
		}
		s.resize(distance(s.begin(), out));
	}
};
