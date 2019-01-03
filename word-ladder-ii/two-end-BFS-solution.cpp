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

		vector<int> d1(n + 1, INT_MAX), d2(n + 1, INT_MAX);
		unordered_set<int> s1{n}, s2{target}, mid;
		d1[n] = 1, d2[target] = 1;
		vector<vector<int>> parent1(n + 1), parent2(n + 1);

		for (int len = 2; !s1.empty(); ++len) {
			unordered_set<int> next;
			for (int u : s1) {
				for (int v : getAdjList(u)) {
					if (s2.count(v))
						mid.insert(v);
					if (d1[u] + 1 < d1[v])
						next.insert(v), d1[v] = d1[u] + 1;
					if (d1[u] + 1 == d1[v])
						parent1[v].push_back(u);
				}
			}
			s1 = move(next);
			if (s1.size() > s2.size())
				swap(s1, s2), swap(d1, d2), swap(parent1, parent2);
			if (!mid.empty())
				goto outputPaths;
		}
		return {};

outputPaths:
		if (d1[n] != 1)
			swap(s1, s2), swap(d1, d2), swap(parent1, parent2);
		vector<vector<string>> ans;
		deque<int> path;
		F backtrackToTarget = [&](int u) {
			if (u == target) {
				ans.emplace_back();
				for (auto it = path.begin(); it != path.end(); ++it)
					ans.back().push_back((*it < n) ? wordList[*it] : beginWord);
			} else {
				for (int v : parent2[u])
					path.push_back(v), backtrackToTarget(v), path.pop_back();
			}
		};
		F backtrackToSource = [&](int u) {
			path.push_front(u);
			if (u == n) {
				backtrackToTarget(path.back());
			} else {
				for (int v : parent1[u])
					backtrackToSource(v);
			}
			path.pop_front();
		};
		for (int v : mid)
			backtrackToSource(v);
		return ans;
	}
};
