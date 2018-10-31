class Solution {
public:
	/* time: O(total # of output char), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<string> fullJustify(const vector<string>& words, int maxWidth) {
		vector<string> ans;
		auto writeLine = [&](auto first, auto last, bool isLastLine) {
			int nChar = 0, nWord = 0;
			for (auto it = first; it != last; ++it)
				nChar += it->size(), ++nWord;

			if (nWord == 1 || (isLastLine && nWord > 0)) {
				ans.emplace_back();
				for (auto it = first; it != last; ++it) {
					ans.back().append(*it);
					if (it != last - 1)
						ans.back().push_back(' ');
				}
				ans.back().append(maxWidth - ans.back().size(), ' ');
			} else if (nWord > 1) {
				int quotient = (maxWidth - nChar) / (nWord - 1);
				int remainder = (maxWidth - nChar) % (nWord - 1);

				ans.emplace_back();
				for (auto it = first; it != last; ++it) {
					ans.back().append(*it);
					if (it != last - 1) {
						ans.back().append(quotient, ' ');
						if (remainder)
							--remainder, ans.back().push_back(' ');
					}
				}
			}
		};

		int width = -1;
		auto L = words.begin();
		for (auto R = words.begin(); R != words.end(); ++R) {
			if (width + 1 + R->size() > maxWidth)
				writeLine(L, R, false), L = R, width = -1;
			width += 1 + R->size();
		}
		writeLine(L, words.end(), true);
		return ans;
	}
};
