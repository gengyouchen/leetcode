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
	/* time: O(n*m), space: O(n), where n = |S|, m = |T| */
	static string minWindow(const string& S, const string& T) {
		const int n = S.size(), m = T.size();
		const LetterFinder f(S);

		int ansPos = -1, ansLen = INT_MAX;
		for (int L = 0; L < n; ++L) {
			int R = L;
			bool matched = true;
			for (char c : T) {
				R = f.find(c, R);
				if (R == -1) {
					matched = false;
					break;
				}
				++R;
			}
			if (matched) {
				const int len = R - L;
				if (len < ansLen)
					ansPos = L, ansLen = len;
			}
		}
		return (ansPos == -1) ? "" : S.substr(ansPos, ansLen);
	}
};
