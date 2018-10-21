class Solution {
public:
	/* O(len(needle) + len(haystack)) time, O(len(needle)) space */
	int strStr(const string& haystack, const string& needle) {
		if (needle.empty())
			return 0;

		auto myMod = [](int x) {
			const int p = 12421; /* any large prime is okay */
			return (x % p + p) % p; /* we want (x % p) >= 0 */
		};
		auto myPow = [&](int x, int a) {
			int ans = 1, curr = myMod(x);
			/* Use "Repeated Squaring" method (see CLRS textbook 31.6) */
			for (int bit = 1; bit; bit <<= 1) {
				if (a & bit)
					ans = myMod(ans * curr);
				curr = myMod(curr * curr);
			}
			return ans;
		};
		auto hash = [&](const string& s) {
			int key = 0;
			for (char c : s)
				key = myMod(key * 256 + c);
			return key;
		};

		const int n = haystack.size(), m = needle.size(), w = myPow(256, m - 1);
		const int target = hash(needle);
		int rollingHash = hash(haystack.substr(0, m));

		for (int L = 0, R = m - 1; R < n; ++L, ++R) {
			if (rollingHash == target)
				if (haystack.substr(L, m) == needle)
					return L; /* found */

			if (R != n - 1)
				rollingHash = myMod((rollingHash - haystack[L] * w) * 256 + haystack[R + 1]);
		}
		return -1; /* not found */
	}
};
