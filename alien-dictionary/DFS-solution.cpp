class Solution {
private:
	enum Color { WHITE, GRAY, BLACK };
public:
	/*
	 * time: O(n), space: O(|V| + |E|)
	 * where n = total # of chars in all words, |V| = |charset(words)|, |E| = words.size()
	 */
	string alienOrder(const vector<string>& words) {
		unordered_map<char, unordered_set<char>> adjLists;
		for (const auto& word : words) {
			for (const char c : word)
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

		unordered_map<char, int> color;
		unordered_map<char, unordered_set<char>::iterator> adjIter;
		for (const auto& p : adjLists) {
			const char u = p.first;
			adjIter[u] = adjLists[u].begin();
		}

		string ans;
		auto dfsVisit = [&](char src) -> bool {
			stack<char> s;
			s.push(src);
			while (!s.empty()) {
				const char u = s.top();
				switch (color[u]) {
				case WHITE:
					color[u] = GRAY;
				case GRAY:
					if (adjIter[u] != adjLists[u].end()) {
						const char v = *adjIter[u]++;
						if (color[v] == GRAY) /* back edge */
							return false;
						if (color[v] == WHITE) /* tree edge */
							s.push(v);
						continue;
					}
					color[u] = BLACK;
				case BLACK:
					ans.push_back(u);
					s.pop();
				}
			}
			return true;
		};
		auto dfs = [&]() -> bool {
			for (const auto& p : adjLists) {
				const char u = p.first;
				if (color[u] == WHITE) {
					if (!dfsVisit(u))
						return false;
				}
			}
			return true;
		};
		if (!dfs())
			return "";
		reverse(ans.begin(), ans.end()); /* get finishing order */
		return ans;
	}
};
