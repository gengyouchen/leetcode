class Counter {
private:
	int char2count[128] = {}, char2threshold[128] = {};
	int nMatched = 0, nTargeted;
public:
	Counter(const string& target) : nTargeted(target.size()) {
		for (char c : target)
			++char2threshold[c];
	}
	void add(char c) {
		if (char2threshold[c] && char2count[c]++ < char2threshold[c])
			++nMatched;
	};
	void remove(char c) {
		if (char2threshold[c] && --char2count[c] < char2threshold[c])
			--nMatched;
	}
	bool isMatched() const { return nMatched == nTargeted; }
};

class Solution {
public:
	/* time: O(|s| + |t|), space: O(|charset|) */
	static string minWindow(const string& s, const string& t) {
		const int n = s.size();
		Counter window(t);
		int ansL = 0, ansR = INT_MAX, L = 0;
		for (int R = 0; R < n; ++R) {
			window.add(s[R]);
			while (window.isMatched()) {
				if (R - L < ansR - ansL)
					ansL = L, ansR = R;
				window.remove(s[L++]);
			}
		}
		return (ansR == INT_MAX) ? "" : s.substr(ansL, ansR - ansL + 1);
	}
};
