class Solution {
private:
	enum Color { WHITE, GRAY, BLACK };
public:
	/* time: O(n + |edges|), space: O(n + |edges|) */
	bool validTree(int n, const vector<pair<int, int>>& edges) {
		vector<vector<int>> adjLists(n);
		for (const auto& edge : edges) {
			const int u = edge.first, v = edge.second;
			adjLists[u].push_back(v);
			adjLists[v].push_back(u);
		}

		vector<int> color(n), parent(n, -1);
		vector<vector<int>::iterator> adjIter(n);
		for (int u = 0; u < n; ++u)
			adjIter[u] = adjLists[u].begin();

		auto dfsVisit = [&](int src) -> bool {
			stack<int> s;
			s.push(src);
			while (!s.empty()) {
				const int u = s.top();
				switch (color[u]) {
				case WHITE:
					color[u] = GRAY;
				case GRAY:
					if (adjIter[u] != adjLists[u].end()) {
						const int v = *adjIter[u]++;
						if (v != parent[u]) {
							if (color[v] == GRAY) /* back edge */
								return false;
							if (color[v] == WHITE) /* tree edge */
								s.push(v), parent[v] = u;
						}
						continue;
					}
					color[u] = BLACK;
				case BLACK:
					s.pop();
				}
			}
			return true;
		};
		if (!dfsVisit(0))
			return false;
		for (int u = 0; u < n; ++u) {
			if (color[u] != BLACK)
				return false;
		}
		return true;
	}
};
