class Solution {
public:
	/* time: O(L + n^2), space: O(n), where n = # of words, L = total # of chars in all words */
	static int maxProduct(const vector<string>& words) {
		const int n = words.size();
		vector<int> masks(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (char c : words[i])
				masks[i] |= 1 << (c - 'a');
			for (int j = 0; j < i; ++j) {
				if (!(masks[i] & masks[j]))
					ans = max(ans, (int)words[i].size() * (int)words[j].size());
			}
		}
		return ans;
	}
};
