class Solution {
private:
	static vector<int> getKMPTable(const string& str) {
		const int n = str.size();
		vector<int> prefix(n);
		int len = 0;
		for (int i = 1; i < n; ++i) {
			while (len > 0 && str[len] != str[i])
				len = prefix[len - 1];
			if (str[len] == str[i])
				++len;
			prefix[i] = len;
		}
		return prefix;
	}
public:
	/* time: O(n+m), space: O(m), where n = |haystack|, m = |needle| */
	static int strStr(const string& haystack, const string& needle) {
		const int m = needle.size(), n = haystack.size();
		if (m == 0)
			return 0;

		const auto prefix = getKMPTable(needle);
		int len = 0;
		for (int i = 0; i < n; ++i) {
			while (len > 0 && needle[len] != haystack[i])
				len = prefix[len - 1];
			if (needle[len] == haystack[i])
				++len;
			if (len == m)
				return i - (len - 1); /* found */
		}
		return -1; /* not found */
	}
};
