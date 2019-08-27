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
	/*
	 * time: O(n + m), space: O(m), where m = |source|, n = |target|
	 *
	 * <Greedy-choice Property>
	 * Let target can be split into = S0 + S1 + S2 + ...,
	 * where S0, S1, S2, ... are subsequences of source
	 *
	 * We can choose S0 as a longer string as possible.
	 * And then, we use the same strategy for choosing S1, and then S2...
	 * This strategy can always yield a global optima solution.
	 *
	 * <Proof>
	 * Assume there's a global optima solution: target = A0 + A1 + A2 + ..., where |A0| < |S0|.
	 * Let A0 + X = S0.
	 * We can always remove X from A1, A2, ... and then add into the tail of A0 without getting a worse answer.
	 * And then, we can do the same operations for A1, and then A2...
	 * Therefore, target = S0 + S1 + S2 + ... is also a global optima solution.
	 */
	static int shortestWay(const string& source, const string& target) {
		const int n = target.size();
		const LetterFinder f(source);

		int ans = 1, pos = 0;
		for (int i = 0; i < n; ++i) {
			pos = f.find(target[i], pos);
			if (pos == -1) {
				++ans, pos = 0;
				pos = f.find(target[i], pos);
				if (pos == -1)
					return -1;
			}
			++pos;
		}
		return ans;
	}
};
