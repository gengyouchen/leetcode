class Trie {
private:
	bool end = false;
	unordered_map<char, Trie*> next;
public:
	~Trie() {
		for (const auto& it : next)
			delete it.second;
	}
	void insert(const string& s) {
		auto p = this;
		for (char c : s) {
			if (!p->next.count(c))
				p->next[c] = new Trie();
			p = p->next[c];
		}
		p->end = true;
	}
	template <class I, class F>
	void matchAllPrefixes(I first, I last, F onMatched) {
		auto p = this;
		for (auto it = first; it != last; ++it) {
			if (!p->next.count(*it))
				break;
			p = p->next[*it];
			if (p->end)
				onMatched(first, it + 1);
		}
	}
};

class Solution {
public:
	/*
	 * time: O(n^2 + c), space: O(n + c),
	 * where n = len(s), c = total # of characters in wordDict
	 */
	bool wordBreak(const string& s, const vector<string>& wordDict) {
		const int n = s.size();
		Trie dict;
		for (const auto& word : wordDict)
			dict.insert(word);

		/* Let dp[i] is true if-and-only-if wordBreak(s.substr(i), wordDict) is true */
		vector<bool> dp(n, false);
		for (int i = n - 1; i >= 0; --i) {
			dict.matchAllPrefixes(s.begin() + i, s.end(), [&](auto first, auto last) {
				const int len = distance(first, last);
				if (i + len == n || dp[i + len])
					dp[i] = true;
			});
		}
		return dp[0];
	}
};
