class Solution {
public:
	/*
	 * time: O(n), space: O(|V| + |E|)
	 * where n = total # of chars in all words, |V| = |charset(words)|, |E| = words.size()
	 */
	string alienOrder(const vector<string>& words) {
		unordered_map<char, unordered_set<char>> adjLists;
		for (const auto& word : words) {
			for (char c : word)
				adjLists.emplace(c, 26);
		}

		for (int i = 1; i < words.size(); ++i) {
			const auto &prev = words[i - 1], &curr = words[i];
			const int len = min(prev.size(), curr.size());
			for (int j = 0; j < len; ++j) {
				if (prev[j] != curr[j]) {
					adjLists[prev[j]].emplace(curr[j]);
					break;
				}
			}
		}

		unordered_map<char, int> nIndegree;
		for (const auto& p : adjLists) {
			for (int u : p.second)
				++nIndegree[u];
		}

		queue<char> Q;
		for (const auto& p : adjLists) {
			if (!nIndegree[p.first])
				Q.push(p.first);
		}

		string ans;
		while (!Q.empty()) {
			const char u = Q.front();
			Q.pop();
			ans.push_back(u);
			for (int v : adjLists[u]) {
				if (!--nIndegree[v])
					Q.push(v);
			}
		}
		if (ans.size() < adjLists.size())
			return ""; /* failed */
		return ans;
	}
};
