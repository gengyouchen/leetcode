class Solution {
private:
	static bool isVowel(char c) {
		c = tolower(c);
		return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static string reverseVowels(string& s) {
		const int n = s.size();
		int L = 0, R = n - 1;
		while (L < R) {
			if (!isVowel(s[L]))
				++L;
			else if (!isVowel(s[R]))
				--R;
			else
				swap(s[L++], s[R--]);
		}
		return s;
	}
};
