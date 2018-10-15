class Solution {
public:
	/* O(len(needle) + len(haystack)) time, O(len(needle)) space */
	int strStr(const string& haystack, const string& needle) {
		if (needle.empty())
			return 0;

		auto mod = [](int x) {
			const int p = 12421; /* any large prime is okay */
			return (x % p + p) % p; /* we want (x % p) >= 0 */
		};
		auto pow = [&](int x, int a) {
			if (a == 0)
				return 1;
			int ans = mod(x), i = 1;
			while (i * 2 < a)
				ans = mod(ans * ans), i *= 2;
			while (i < a)
				ans = mod(ans * x), ++i;
			return ans;
		};
		auto hash = [&](const string& s) {
			int key = 0;
			for (char c : s)
				key = mod(key * 256 + c);
			return key;
		};

		const int n = haystack.size(), m = needle.size(), w = pow(256, m - 1);
		const int target = hash(needle);
		int rollingHash = hash(haystack.substr(0, m));

		for (int L = 0, R = m - 1; R < n; ++L, ++R) {
			if (rollingHash == target)
				if (haystack.substr(L, m) == needle)
					return L; /* found */

			if (R != n - 1)
				rollingHash = mod((rollingHash - haystack[L] * w) * 256 + haystack[R + 1]);
		}
		return -1; /* not found */
	}
};
