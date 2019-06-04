class Solution {
public:
	/* time: O(n), space: O(|charset|) auxiliary (i.e. does not count output itself) */
	static string removeDuplicateLetters(const string& s) {
		int nRemaining[26] = {};
		bool used[26] = {};
		for (char c : s)
			++nRemaining[c - 'a'];

		string ans;
		for (char c : s) {
			--nRemaining[c - 'a'];
			if (!used[c - 'a']) {
				while (!ans.empty() && ans.back() > c && nRemaining[ans.back() - 'a'])
					used[ans.back() - 'a'] = false, ans.pop_back();
				ans.push_back(c), used[c - 'a'] = true;
			}
		}
		return ans;
	}
};
