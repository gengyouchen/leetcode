class Solution {
public:
	/* time: O(m + n), space: O(m + n), where m = |pattern|, n = |str| */
	static bool wordPattern(const string& pattern, const string& str) {
		const int m = pattern.size(), n = str.size();
		unordered_map<char, string> c2s;
		unordered_map<string, char> s2c;
		int i = 0, j = 0;
		while (i < m && j < n) {
			const int c = pattern[i++];
			string s;
			while (j < n && str[j] != ' ')
				s.push_back(str[j++]);
			if (j < n && str[j] == ' ')
				++j;
			if (c2s.count(c)) {
				if (c2s[c] != s)
					return false;
			} else {
				if (s2c.count(s))
					return false;
				c2s[c] = s, s2c[s] = c;
			}
		}
		return (i == m) && (j == n);
	}
};
