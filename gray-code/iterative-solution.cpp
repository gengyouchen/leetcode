class Solution {
private:
	int lowbit(int x) { return x & -x; }
public:
	/* time: O(2^n), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<int> grayCode(int n) {
		vector<int> ans(1 << n);
		int code = 0;
		for (int i = 0; i < (1 << n); ++i) {
			ans[i] = code;
			if (i % 2)
				code ^= lowbit(code) << 1;
			else
				code ^= 1;
		}
		return ans;
	}
};
