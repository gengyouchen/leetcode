class Solution {
public:
	/* time: O(n^2), space: O(1) */
	string longestPalindrome(const string& s) {
		const int n = s.size() * 2 + 1;
		auto extend = [&](int i) {
			int ri = 1;
			while (i - ri >= 0 && i + ri < n) {
				if ((i - ri) % 2) {
					const int L = (i - ri) / 2;
					const int R = (i + ri) / 2;
					if (s[L] != s[R])
						break;
				}
				++ri;
			}
			return ri;
		};

		int c = -1, rc = 0;
		for (int i = 0; i < n; ++i) {
			const int ri = extend(i);
			if (ri > rc)
				rc = ri, c = i;
		}

		const int L = (c - rc + 2) / 2;
		const int R = (c + rc - 2) / 2;
		return s.substr(L, R - L + 1);
	}
};
