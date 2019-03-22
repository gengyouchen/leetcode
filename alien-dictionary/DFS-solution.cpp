class Solution {
private:
	typedef function<bool(char)> F;
	enum Color { WHITE, GRAY, BLACK };
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

		string ans;
		unordered_map<char, int> color;

		F dfs = [&](char u) {
			color[u] = GRAY;
			for (char v : adjLists[u]) {
				if (color[v] == GRAY) /* u->v is a back edge */
					return false;
				if (color[v] == WHITE) /* u->v is a tree edge */ {
					if (!dfs(v))
						return false;
				}
			}
			color[u] = BLACK;
			ans.push_back(u);
			return true;
		};

		for (auto p : adjLists) {
			if (color[p.first] == WHITE) {
				if (!dfs(p.first))
					return "";
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
