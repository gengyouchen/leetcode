class Solution {
public:
	/* time: O(n * 2^n), space: O(log(n)) auxiliary (i.e. does not count output itself) */
	static vector<string> generateAbbreviations(const string& word) {
		const int n = word.size(), m = 1 << n;
		vector<string> ans(m);
		for (int i = 0; i < m; ++i) {
			int mask = i, out = 0, nSkipped = 0;
			for (int j = 0; j < n; ++j) {
				const int bit = mask & 1;
				mask >>= 1;
				if (bit) {
					if (nSkipped > 0)
						ans[i] += to_string(nSkipped), out += nSkipped;
					ans[i] += word[out++], nSkipped = 0;
				} else {
					++nSkipped;
				}
			}
			if (nSkipped > 0)
				ans[i] += to_string(nSkipped), out += nSkipped;
		}
		return ans;
	}
};
