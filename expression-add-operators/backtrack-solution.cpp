class Solution {
private:
	typedef function<void(int, int, long, long)> F;
public:
	/* time: O(n * 4^n), space: O(n) auxiliary (i.e. does not count output itself) */
	static vector<string> addOperators(const string& num, int target) {
		const int n = num.size();
		vector<string> ans;
		string buf(n * 2 + 1, ' ');
		F backtrack = [&](int in, int out, long prev, long curr) {
			if (in == n) {
				if (prev + curr == target)
					ans.emplace_back(buf, 0, out);
			} else {
				long val = 0;
				for (int i = in; i < n; ++i) {
					const int w = i - in + 1;
					val = val * 10 + (num[i] - '0');
					if (in == 0) {
						buf[out + w - 1] = num[i];
						backtrack(i + 1, out + w, prev + curr, val);
					} else {
						buf[out + w] = num[i];
						buf[out] = '+', backtrack(i + 1, out + w + 1, prev + curr, val);
						buf[out] = '-', backtrack(i + 1, out + w + 1, prev + curr, -val);
						buf[out] = '*', backtrack(i + 1, out + w + 1, prev, curr * val);
					}
					if (num[in] == '0') /* non-zero value cannot start with 0 */
						break;
				}
			}
		};
		backtrack(0, 0, 0, 0);
		return ans;
	}
};
