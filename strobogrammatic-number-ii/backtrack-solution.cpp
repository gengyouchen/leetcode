class Solution {
private:
	typedef function<void(int, int)> F;
public:
	/* time: O(n * 2^n), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<string> findStrobogrammatic(int n) {
		vector<string> ans;
		string buf(n, ' ');
		F backtrack = [&](int i, int j) {
			if (i > j) {
				ans.push_back(buf);
			} else if (i == j) {
				buf[i] = '0', backtrack(i + 1, j - 1);
				buf[i] = '1', backtrack(i + 1, j - 1);
				buf[i] = '8', backtrack(i + 1, j - 1);
			} else {
				if (i != 0)
					buf[i] = '0', buf[j] = '0', backtrack(i + 1, j - 1);
				buf[i] = '1', buf[j] = '1', backtrack(i + 1, j - 1);
				buf[i] = '6', buf[j] = '9', backtrack(i + 1, j - 1);
				buf[i] = '8', buf[j] = '8', backtrack(i + 1, j - 1);
				buf[i] = '9', buf[j] = '6', backtrack(i + 1, j - 1);
			}
		};
		backtrack(0, n - 1);
		return ans;
	}
};
