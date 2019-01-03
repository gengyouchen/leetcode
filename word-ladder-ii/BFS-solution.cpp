class Solution {
private:
	typedef function<void(int)> F;
public:
	/*
	 * time: O(n*L*L + k*n*L), space: O(n*L) auxiliary (i.e. does not count output itself),
	 * where n = # of words, L = each word's size, k = # of shortest transformation sequences
	 */
	vector<vector<string>> findLadders(const string& beginWord, const string& endWord, const vector<string>& wordList) {
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
			return {};
		const int target = it->second;

		vector<int> d(n + 1, INT_MAX);
		queue<int> q;
		q.push(n), d[n] = 1;
		vector<vector<int>> parent(n + 1);

		for (int depth = 1; !q.empty(); ++depth) {
			for (int i = q.size(); i > 0; --i) {
				const int u = q.front();
				q.pop();
				if (u == target)
					goto outputPaths;
				for (int v : getAdjList(u)) {
					if (d[u] + 1 < d[v])
						q.push(v), d[v] = d[u] + 1;
					if (d[u] + 1 == d[v])
						parent[v].push_back(u);
				}
			}
		}
		return {};

outputPaths:
		vector<vector<string>> ans;
		deque<int> path;
		F backtrackToSource = [&](int u) {
			path.push_front(u);
			if (u == n) {
				ans.emplace_back();
				for (int i : path)
					ans.back().push_back((i < n) ? wordList[i] : beginWord);
			} else {
				for (int v : parent[u])
					backtrackToSource(v);
			}
			path.pop_front();
		};
		backtrackToSource(target);
		return ans;
	}
};
