class Solution {
private:
	typedef function<void(int)> F;
public:
	/*
	 * time: O(n*L*L + k*n*L), space: O(n*L) auxiliary (i.e. does not count output itself),
	 * where n = # of words, L = each word's size, k = # of shortest transformation sequences
	 */
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		const int n = wordList.size();
		unordered_map<string, int> word2vertex;
		for (int i = 0; i < n; ++i)
			word2vertex[wordList[i]] = i;
		word2vertex[beginWord] = n;

		vector<vector<int>> adjList(n + 1);
		for (int i = 0; i <= n; ++i) {
			auto buf = (i < n) ? wordList[i] : beginWord;
			for (int j = 0; j < buf.size(); ++j) {
				const char self = buf[j];
				for (int k = 0; k < 26; ++k) {
					buf[j] = 'a' + k;
					if (buf[j] != self) {
						const auto it = word2vertex.find(buf);
						if (it != word2vertex.end())
							adjList[i].push_back(it->second);
					}
				}
				buf[j] = self;
			}
		}

		const auto it = word2vertex.find(endWord);
		if (it == word2vertex.end())
			return {};
		const int target = it->second;

		vector<int> d(n + 1, INT_MAX);
		queue<int> q;
		q.push(n), d[n] = 1;

		for (int depth = 1; !q.empty(); ++depth) {
			for (int i = q.size(); i > 0; --i) {
				const int u = q.front();
				q.pop();
				if (u == target)
					goto outputPaths;
				for (int v : adjList[u]) {
					if (d[u] + 1 < d[v])
						q.push(v), d[v] = d[u] + 1;
				}
			}
		}
		return {};

outputPaths:
		vector<vector<string>> ans;
		vector<int> path;
		F backtrack = [&](int u) {
			path.push_back(u);
			if (u == n) {
				ans.emplace_back();
				for (auto it = path.rbegin(); it != path.rend(); ++it)
					ans.back().push_back((*it < n) ? wordList[*it] : beginWord);
			} else {
				for (int v : adjList[u]) {
					if (d[v] == d[u] - 1)
						backtrack(v);
				}
			}
			path.pop_back();
		};
		backtrack(target);
		return ans;
	}
};
