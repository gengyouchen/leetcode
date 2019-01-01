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
		queue<int> q;
		q.push(n), discovered[n] = true;

		for (int depth = 1; !q.empty(); ++depth) {
			for (int i = q.size(); i > 0; --i) {
				const int u = q.front();
				q.pop();
				if (u == target)
					return depth;
				for (int v : getAdjList(u)) {
					if (!discovered[v])
						q.push(v), discovered[v] = true;
				}
			}
		}
		return 0;
	}
};
