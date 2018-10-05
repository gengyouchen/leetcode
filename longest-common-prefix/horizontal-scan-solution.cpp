class Solution {
public:
	/* time: O(# of chars), space: O(1) auxiliary (i.e. does not count output itself) */
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		int ans = strs[0].size();
		for (int i = 1; i < strs.size(); ++i) {
			ans = min(ans, (int)strs[i].size());
			for (int j = 0; j < ans; ++j)
				if (strs[i][j] != strs[i - 1][j]) {
					ans = j;
					break;
				}
		}
		return strs[0].substr(0, ans);
	}
};
