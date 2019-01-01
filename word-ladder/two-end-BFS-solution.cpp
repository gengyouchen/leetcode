class Solution {
public:
	/* time: O(n*L*L), space: O(n*L), where n = # of words, L = each word's size */
	int ladderLength(const string& beginWord, const string& endWord, const vector<string>& wordList) {
		const int n = wordList.size();
		auto word2vertex = unordered_map<string, int>();
		for (int i = 0; i < n; ++i)
			word2vertex[wordList[i]] = i;
		word2vertex[beginWord] = n;
		if (!word2vertex.count(endWord))
			return 0;

		auto getAdjList = [&](int i) {
			vector<int> adjList;
			auto buf = (i < n) ? wordList[i] : beginWord;
			for (int j = 0; j < buf.size(); ++j) {
				char self = buf[j];
				for (int k = 0; k < 26; ++k) {
					buf[j] = 'a' + k;
					if (buf[j] != self) {
						auto it = word2vertex.find(buf);
						if (it != word2vertex.end())
							adjList.push_back(it->second);
					}
				}
				buf[j] = self;
			}
			return adjList;
		};

		auto visited = vector<bool>(n + 1, false);
		auto source = unordered_set<int>{n};
		auto target = unordered_set<int>{word2vertex[endWord]};
		visited[n] = visited[word2vertex[endWord]] = true;

		int ans = 2;
		while (!source.empty()) {
			auto nextSource = unordered_set<int>();
			for (int u : source) {
				for (int v : getAdjList(u)) {
					if (target.count(v))
						return ans;
					if (!visited[v]) {
						visited[v] = true;
						nextSource.insert(v);
					}
				}
			}
			source = move(nextSource);
			if (source.size() > target.size())
				swap(source, target);
			++ans;
		}
		return 0;
	}
};
