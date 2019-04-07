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
private:
	typedef function<void(int)> F;
public:
	/*
	 * time: O(n^2 + c + d), space: O(n^2 + c) auxiliary (i.e. does not count output itself),
	 * where n = len(s), c = total # of characters in wordDict, d = total # of output characters
	 */
	vector<string> wordBreak(const string& s, const vector<string>& wordDict) {
		const int n = s.size();
		Trie dict;
		for (const auto& word : wordDict)
			dict.insert(word);

		/*
		 * Modified from LeetCode 139 - Word Break problem:
		 * Let dp[i] be a list containing all index j satisfying
		 * (s[i:j] is in wordDict) && (wordBreak(s[j:n]) == true)
		 *
		 * Therefore, DP table becomes a graph (adjacency list)
		 * This doesn't change the DP algorithm
		 * We just record more information in DP table
		 */
		vector<vector<int>> dp(n);
		for (int i = n - 1; i >= 0; --i) {
			dict.matchAllPrefixes(s.begin() + i, s.end(), [&](auto first, auto last) {
				const int len = distance(first, last);
				if (i + len == n || !dp[i + len].empty())
					dp[i].push_back(i + len);
			});
		}

		vector<string> ans;
		vector<int> buf;
		F backtrack = [&](int pos) {
			if (pos == n) {
				ans.emplace_back();
				int i = 0;
				for (int ws : buf) {
					while (i < ws)
						ans.back().push_back(s[i++]);
					if (i < n)
						ans.back().push_back(' ');
				}
			} else {
				for (int next : dp[pos]) {
					buf.push_back(next);
					backtrack(next);
					buf.pop_back();
				}
			}
		};
		backtrack(0);
		return ans;
	}
};
