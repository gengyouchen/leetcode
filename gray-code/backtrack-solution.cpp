class Solution {
private:
	typedef function<void(int, int, bool)> F;
public:
	/* time: O(2^n), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<int> grayCode(int n) {
		vector<int> ans;
		F backtrack = [&](int step, int code, bool mirrowed) {
			if (step == n)
				ans.push_back(code);
			else if (mirrowed) {
				backtrack(step + 1, code << 1 | 1, !mirrowed);
				backtrack(step + 1, code << 1 | 0, mirrowed);
			} else {
				backtrack(step + 1, code << 1 | 0, mirrowed);
				backtrack(step + 1, code << 1 | 1, !mirrowed);
			}
		};
		backtrack(0, 0, false);
		return ans;
	}
};
