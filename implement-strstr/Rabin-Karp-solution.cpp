#define MOD 1000000007

class RollingHash {
private:
	using LL = long long;
	static LL mod(LL x) {
		const LL ret = x % MOD;
		return (ret >= 0) ? ret : (ret + MOD);
	}
	LL h = 0, w = 0;
public:
	template <class I>
	RollingHash(I first, I last) {
		for (auto it = first; it != last; ++it)
			h = mod(h * 256 + *it), w = w ? mod(w * 256) : 1;
	}
	void roll(char L, char R) { h = mod((h - w * L) * 256 + R); }
	operator int() const { return h; }
};

class Solution {
public:
	/* time: O(n+m) expected, space: O(1), where n = |haystack|, m = |needle| */
	static int strStr(const string& haystack, const string& needle) {
		const int m = needle.size(), n = haystack.size();
		if (m > n)
			return -1;

		const RollingHash goal(needle.begin(), needle.end());
		RollingHash curr(haystack.begin(), haystack.begin() + m);
		for (int L = 0, R = m - 1; R < n; ++L, ++R) {
			if (curr == goal && !haystack.compare(L, m, needle))
				return L; /* found */

			if (R != n - 1)
				curr.roll(haystack[L], haystack[R + 1]);
		}
		return -1; /* not found */
	}
};
