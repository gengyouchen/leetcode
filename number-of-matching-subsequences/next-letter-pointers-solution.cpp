class LetterFinder {
private:
	vector<array<int, 26>> nextPos;
public:
	LetterFinder(const string& str) : nextPos(str.size()) {
		const int n = nextPos.size();
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1)
				fill(nextPos[i].begin(), nextPos[i].end(), -1);
			else
				nextPos[i] = nextPos[i + 1];
			nextPos[i][str[i] - 'a'] = i;
		}
	}
	int find(char c, int pos) const {
		const int n = nextPos.size();
		if (pos >= n)
			return -1;
		return nextPos[pos][c - 'a'];
	}
};

class Solution {
public:
	/* time: O(n + m), space: O(n), where n = |S|, m = total # of chars in words */
	static int numMatchingSubseq(const string& S, const vector<string>& words) {
		LetterFinder f(S);
		int ans = 0;
		for (const auto& word : words) {
			bool matched = true;
			int pos = 0;
			for (char c : word) {
				pos = f.find(c, pos);
				if (pos == -1) {
					matched = false;
					break;
				}
				++pos;
			}
			if (matched)
				++ans;
		}
		return ans;
	}
};
