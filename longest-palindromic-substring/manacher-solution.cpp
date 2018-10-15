class Solution {
private:
	vector<int> manacher(const string &s) {
		auto r = vector<int>(s.size() * 2 + 1, 1);
		auto extend = [&](int i) {
			while (i - r[i] >= 0 && i + r[i] < r.size()) {
				if ((i - r[i]) % 2) {
					int L = (i - r[i]) / 2;
					int R = (i + r[i]) / 2;
					if (s[L] != s[R])
						break;
				}
				++r[i];
			}
		};

		int c = 0;
		for (int i = 0; i < r.size(); ++i) {
			if (i >= c + r[c]) {
				extend(i);
				c = i;
			} else {
				int j = c - (i - c);
				if (i + r[j] > c + r[c])
					r[i] = c + r[c] - i;
				else if (i + r[j] < c + r[c])
					r[i] = r[j];
				else {
					r[i] = r[j];
					extend(i);
					c = i;
				}
			}
		}
		return r;
	}
public:
	/* time: O(n), space: O(n) */
	string longestPalindrome(const string& s) {
		auto r = manacher(s);
		int c = distance(r.begin(), max_element(r.begin(), r.end()));

		int L = (c - r[c] + 2) / 2;
		int R = (c + r[c] - 2) / 2;
		return s.substr(L, R - L + 1);
	}
};
