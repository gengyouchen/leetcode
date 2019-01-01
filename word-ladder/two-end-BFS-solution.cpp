class Solution {
public:
	/* time: O(n*L*L), space: O(n*L), where n = # of words, L = each word's size */
	int ladderLength(const string& beginWord, const string& endWord, const vector<string>& wordList) {
		const int n = wordList.size();
		unordered_map<string, int> word2vertex;
		for (int i = 0; i < n; ++i)
			word2vertex[wordList[i]] = i;
		word2vertex[beginWord] = n;

		auto getAdjList = [&](int i) {
			vector<int> adjList;
			auto buf = (i < n) ? wordList[i] : beginWord;
			for (int j = 0; j < buf.size(); ++j) {
				const char self = buf[j];
				for (int k = 0; k < 26; ++k) {
					buf[j] = 'a' + k;
					if (buf[j] != self) {
						const auto it = word2vertex.find(buf);
						if (it != word2vertex.end())
							adjList.push_back(it->second);
					}
				}
				buf[j] = self;
			}
			return adjList;
		};

		const auto it = word2vertex.find(endWord);
		if (it == word2vertex.end())
			return 0;
		const int target = it->second;

		vector<bool> discovered(n + 1, false);
		unordered_set<int> s1{n}, s2{target};
		discovered[n] = discovered[target] = true;

		for (int len = 2; !s1.empty(); ++len) {
			unordered_set<int> next;
			for (int u : s1) {
				for (int v : getAdjList(u)) {
					if (s2.count(v))
						return len;
					if (!discovered[v])
						next.insert(v), discovered[v] = true;
				}
			}
			s1 = move(next);
			if (s1.size() > s2.size())
				swap(s1, s2);
		}
		return 0;
	}
};
