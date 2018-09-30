class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	string convert(const string& s, int numRows) {
		string ans;
		ans.resize(s.size());
		int out = 0;

		const int d = numRows + max(numRows - 2, 0);
		for (int row = 0; row < numRows; ++row)
			for (int i = row, j = d - row; i < s.size(); i += d, j += d) {
				ans[out++] = s[i];
				if (row > 0 && row < numRows - 1 && j < s.size())
					ans[out++] = s[j];
			}
		return ans;
	}
};
