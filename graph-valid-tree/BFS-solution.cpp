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

		vector<int> color(n);
		queue<int> q;
		q.push(0), color[0] = GRAY;
		while (!q.empty()) {
			const int u = q.front();
			q.pop();
			for (const int v : adjLists[u]) {
				if (color[v] == GRAY) /* cross edge */
					return false;
				if (color[v] == WHITE) /* tree edge */
					q.push(v), color[v] = GRAY;
			}
			color[u] = BLACK;
		}

		for (int u = 0; u < n; ++u) {
			if (color[u] != BLACK)
				return false;
		}
		return true;
	}
};
