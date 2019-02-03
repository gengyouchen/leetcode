class Solution {
public:
	/*
	 * time: O(n + k*m), space: O(4^m) auxiliary (i.e. does not count output itself)
	 * where m = length of each sequence = 10, k = # of output duplicated sequences
	 */
	vector<string> findRepeatedDnaSequences(const string& s) {
		const int n = s.size(), m = 10, w = 1 << (2 * m);
		auto hash = [&](int L, int R) {
			int key = 0;
			for (int i = L; i < R; ++i)
				key = key * 4 + ((s[i] == 'A') ? 0 : (s[i] == 'T') ? 1 : (s[i] == 'G') ? 2 : 3);
			return key;
		};

		vector<string> ans;
		bitset<w> appeared, repeated;
		int rollingHash = hash(0, m);
		for (int L = 0, R = m; R <= n; ++L, ++R) {
			if (appeared.test(rollingHash)) {
				if (!repeated.test(rollingHash)) {
					ans.emplace_back();
					for (int i = L; i < R; ++i)
						ans.back().push_back(s[i]);
					repeated.set(rollingHash);
				}
			} else {
				appeared.set(rollingHash);
			}
			if (R != n)
				rollingHash = (rollingHash * 4) % w + ((s[R] == 'A') ? 0 : (s[R] == 'T') ? 1 : (s[R] == 'G') ? 2 : 3);
		}
		return ans;
	}
};
