class Solution {
private:
	vector<int> kmpTable(const string& s) {
		/*
		 *                    prefix   suffix
		 *                    =====    =====
		 * e.g. when R=13, s="ababa9487ababa..."
		 *                        ^        ^
		 *                        L=4      R=13
		 *
		 *                    =====    =====
		 * Now, when R=14, s="ababa9487ababab..."
		 *                         ^        ^
		 *                        L+1       R=14
		 *
		 * Because '9' != 'b', we cannot ++L anymore
		 * However, we do NOT need to restart L=-1
		 *
		 *                                   ===
		 *                                     ===
		 * Reuse the previous R=4 result of "ababa..."
		 *                                     ^ ^
		 *                                     L R=4
		 *
		 *                        ===        ===
		 * We can restart L=2, s="ababa9487ababab..."
		 *                           ^          ^
		 *                          L+1         R
		 *
		 * Because 'b' == 'b', we can now ++L
		 *
		 *                    ====       ====
		 * Now, when R=14, s="ababa9487ababab..."
		 *                       ^          ^
		 *                       L          R
		 */
		vector<int> R2L(s.size());
		R2L[0] = -1;
		int L = -1;
		for (int R = 1; R < s.size(); ++R) {
			while (L >= 0 && s[L + 1] != s[R])
				L = R2L[L];
			if (s[L + 1] == s[R])
				++L;
			R2L[R] = L;
		}
		return R2L;
	}
public:
	/* O(len(needle) + len(haystack)) time, O(len(needle)) space */
	int strStr(const string& haystack, const string& needle) {
		if (needle.empty())
			return 0;

		const auto R2L = kmpTable(needle);
		int L = -1;
		for (int R = 0; R < haystack.size(); ++R) {
			while (L >= 0 && needle[L + 1] != haystack[R])
				L = R2L[L];
			if (needle[L + 1] == haystack[R])
				L++;
			if (L == needle.size() - 1) {
				return R - L; /* found */
				L = R2L[L]; /* find next */
			}
		}
		return -1; /* not found */
	}
};
