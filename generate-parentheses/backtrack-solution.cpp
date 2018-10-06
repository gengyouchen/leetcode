class Solution {
private:
	typedef function<void(int, int)> F;
public:
	/* time: O(n-th Catalan Number * n), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		string buf(n * 2, '?');
		F backtrack = [&](int nOpened, int nClosed) {
			const int i = nOpened + nClosed;
			if (i < n * 2) {
				if (nOpened < n)
					buf[i] = '(', backtrack(nOpened + 1, nClosed);
				if (nClosed < nOpened)
					buf[i] = ')', backtrack(nOpened, nClosed + 1);
			} else
				ans.push_back(buf);
		};
		backtrack(0, 0);
		return ans;
	}
};
