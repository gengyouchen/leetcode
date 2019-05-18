class Solution {
private:
	typedef function<void(int, int, int, int, int)> F;
public:
	/* time: O(n * 2^n), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<string> removeInvalidParentheses(const string& s) {
		const int n = s.size();
		int unmatchedL = 0, unmatchedR = 0;
		for (char c : s) {
			if (c == '(') {
				++unmatchedL;
			} else if (c == ')') {
				if (unmatchedL > 0)
					--unmatchedL;
				else
					++unmatchedR;
			}
		}
		vector<string> ans;
		string buf(n, ' ');
		F backtrack = [&](int in, int out, int opened, int skippedL, int skippedR) {
			for (int k = in; k < n && opened >= 0; ++k) {
				if (s[k] == '(') {
					if (skippedL < unmatchedL && (k == in || s[k - 1] != '('))
						backtrack(k + 1, out, opened, skippedL + 1, skippedR);
					++opened;
				} else if (s[k] == ')') {
					if (skippedR < unmatchedR && (k == in || s[k - 1] != ')'))
						backtrack(k + 1, out, opened, skippedL, skippedR + 1);
					--opened;
				}
				buf[out++] = s[k];
			}
			if (skippedL == unmatchedL && skippedR == unmatchedR && opened == 0)
				ans.emplace_back(buf, 0, out);
		};
		backtrack(0, 0, 0, 0, 0);
		return ans;
	}
};
