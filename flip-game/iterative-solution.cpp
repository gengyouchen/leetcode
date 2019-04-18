class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<string> generatePossibleNextMoves(string& s) {
		const int n = s.size();
		vector<string> ans;
		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == '+' && s[i + 1] == '+')
				s[i] = s[i + 1] = '-', ans.push_back(s), s[i] = s[i + 1] = '+';
		}
		return ans;
	}
};
