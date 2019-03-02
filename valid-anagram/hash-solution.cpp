class Solution {
public:
	/* time: O(n), space: O(size(charset)), where n = len(s) = len(t) */
	bool isAnagram(const string& s, const string& t) {
		if (s.size() != t.size())
			return false;
		int count[26] = {};
		for (char c : s)
			++count[c - 'a'];
		for (char c : t)
			--count[c - 'a'];
		for (int i = 0; i < 26; ++i) {
			if (count[i])
				return false;
		}
		return true;
	}

