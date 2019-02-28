class Solution {
public:
	/* time: O(n), space: O(1), where n = total # of chars in words */
	int shortestDistance(const vector<string>& words, const string& word1, const string& word2) {
		const int n = words.size();
		int ans = INT_MAX;
		int p = -1, q = -1;
		for (int i = 0; i < n; ++i) {
			if (words[i] == word1)
				p = i;
			else if (words[i] == word2)
				q = i;

			if (p != -1 && q != -1)
				ans = min(ans, abs(p - q));
		}
		return ans;
	}
};
