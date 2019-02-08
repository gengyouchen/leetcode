class Solution {
public:
	/* time: O(n), space: O(size(charset)) */
	bool isIsomorphic(const string &s, const string &t) {
		if (s.size() != t.size())
			return false;
		const int n = s.size();
		unsigned char s2t[256] = {}, t2s[256] = {};
		for (int i = 0; i < n; ++i) {
			const unsigned char p = s[i], q = t[i];
			if (!s2t[p] && !t2s[q])
				s2t[p] = q, t2s[q] = p;
			else if (s2t[p] != q || t2s[q] != p)
				return false;
		}
		return true;
	}
};
