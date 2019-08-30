class Solution {
public:
	/*
	 * time: O(k * 26^k), space: O(n) auxiliary (i.e. does not count output itself),
	 * where n = |S|, k = # of chars in each output string
	 */
	static vector<string> expand(const string& S) {
		const int n = S.size();
		vector<vector<char>> level2chars;
		for (int i = 0; i < n; ++i) {
			const char c = S[i];
			if (i == 0) {
				level2chars.emplace_back();
			} else if (isalpha(c) || c == '{') {
				const char prev = S[i - 1];
				if (isalpha(prev) || prev == '}')
					level2chars.emplace_back();
			}

			if (isalpha(c))
				level2chars.back().push_back(c);
		}

		const int k = level2chars.size();
		for (int i = 0; i < k; ++i)
			sort(level2chars[i].begin(), level2chars[i].end());

		vector<string> ans;
		string buf;
		using F = function<void(int)>;
		F backtrack = [&](int step) {
			if (step == k) {
				ans.push_back(buf);
			} else {
				for (char c : level2chars[step])
					buf.push_back(c), backtrack(step + 1), buf.pop_back();
			}
		};
		backtrack(0);
		return ans;
	}
};
