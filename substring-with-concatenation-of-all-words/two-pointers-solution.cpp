class Solution {
public:
	/* time: O(len(s) * len(one word)), space: O(len(all words)) auxiliary (i.e. does not count output itself) */
	vector<int> findSubstring(const string& s, vector<string>& words) {
		if (words.empty())
			return {};

		const int n = s.size(), m = words[0].size();
		unordered_map<string, int> unmatched;
		int totalUnmatched = 0;
		for (const string& word : words)
			++unmatched[word], ++totalUnmatched;

		auto canMatch = [&](int pos) {
			auto it = unmatched.find(s.substr(pos, m));
			return it != unmatched.end() && it->second > 0;
		};
		auto match = [&](int pos) {
			--unmatched[s.substr(pos, m)], --totalUnmatched;
		};
		auto unmatch = [&](int pos) {
			++unmatched[s.substr(pos, m)], ++totalUnmatched;
		};

		vector<int> ans;
		for (int begin = 0; begin < m; ++begin) {
			int L = begin;
			for (int R = begin; R + m <= n; R += m) {
				while (L < R && !canMatch(R))
					unmatch(L), L += m;
				if (L == R && !canMatch(R))
					L += m;
				else {
					match(R);
					if (totalUnmatched == 0)
						ans.push_back(L);
				}
			}
			while (L + m <= n)
				unmatch(L), L += m;
		}
		return ans;
	}
};
