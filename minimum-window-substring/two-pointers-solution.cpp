class Solution {
public:
	/* time: O(len(s) + len(t)), space: O(len(t)) auxiliary (i.e. does not count output itself) */
	string minWindow(const string& s, const string& t) {
		unordered_map<char, int> unmatched;
		int totalUnmatched = 0;
		for (char c : t)
			++unmatched[c], ++totalUnmatched;

		auto match = [&](char c) {
			auto it = unmatched.find(c);
			if (it != unmatched.end()) {
				it->second--;
				if (it->second >= 0)
					--totalUnmatched;
			}
		};
		auto canUnmatch = [&](char c) {
			auto it = unmatched.find(c);
			return (it == unmatched.end()) || (it->second < 0);
		};
		auto unmatch = [&](char c) {
			auto it = unmatched.find(c);
			if (it != unmatched.end()) {
				if (it->second >= 0)
					++totalUnmatched;
				it->second++;
			}
		};

		int minLen = INT_MAX;
		auto L = s.begin(), ansFirst = s.end(), ansLast = s.end();
		for (auto R = s.begin(); R != s.end(); ++R) {
			match(*R);
			while (L < R && canUnmatch(*L))
				unmatch(*L++);
			if (totalUnmatched <= 0 && distance(L, R + 1) < minLen)
				minLen = distance(L, R + 1), ansFirst = L, ansLast = R + 1;
		}
		return string(ansFirst, ansLast);
	}
};
