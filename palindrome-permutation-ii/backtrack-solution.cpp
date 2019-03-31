class Solution {
private:
	typedef function<void(int, int)> F;
public:
	/*
	 * time: O(n * w!), space: O(n + |charset|) auxiliary (i.e. does not count output itself),
	 * where n = s.size(), w = n / 2 + 1
	 */
	vector<string> generatePalindromes(const string& s) {
		const int n = s.size();
		int h[256] = {};
		for (unsigned char c : s)
			++h[c];
		int odd = -1;
		for (int c = 0; c < 256; ++c) {
			if (h[c] % 2) {
				if (odd != -1)
					return {};
				odd = c;
			}
		}
		for (int c = 0; c < 256; ++c)
			h[c] /= 2;

		vector<string> ans;
		string buf(n, ' ');
		F backtrack = [&](int i, int j) {
			if (i > j) {
				ans.push_back(buf);
			} else if (i == j) {
				buf[i] = odd;
				ans.push_back(buf);
			} else {
				for (int c = 0; c < 256; ++c) {
					if (h[c]) {
						--h[c];
						buf[i] = buf[j] = (unsigned char)c;
						backtrack(i + 1, j - 1);
						++h[c];
					}
				}
			}
		};
		backtrack(0, n - 1);
		return ans;
	}
};
