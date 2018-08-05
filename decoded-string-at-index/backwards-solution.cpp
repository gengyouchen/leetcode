class Solution {
public:
	/* time: O(N), space: O(1) */
	string decodeAtIndex(string S, int K) {
		--K; /* convert to 0-indexed */

		long len = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (isdigit(S[i]))
				len *= S[i] - '0';
			else
				++len;

			/* tips: prevent len from overflow */
			if (K < len)
				S.resize(i + 1);
		}

		for (int i = S.size() - 1; i >= 0; --i)
			if (isdigit(S[i]))
				len /= S[i] - '0', K %= len;
			else if (K < len - 1)
				--len;
			else
				return S.substr(i, 1); /* succeed */

		return ""; /* failed */
	}
};
