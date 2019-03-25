class Solution {
private:
	enum Color { WHITE, GRAY, BLACK };
public:
	/*
	 * time: O(|V| + |E|), space: O(|V| + |E|)
	 * where |V| = numCourses, |E| = len(prerequisites)
	 */
	vector<int> findOrder(int numCourses, const vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> adjLists(numCourses);
		for (const auto& p : prerequisites) {
			const int u = p.second, v = p.first;
			adjLists[u].push_back(v);
		}

		vector<int> color(numCourses);
		vector<vector<int>::iterator> adjIter(numCourses);
		for (int u = 0; u < numCourses; ++u)
			adjIter[u] = adjLists[u].begin();

		vector<int> ans;
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
			for (int u = 0; u < numCourses; ++u) {
				if (color[u] == WHITE && !dfsVisit(u))
					return false;
			}
			return true;
		};
		if (!dfs())
			return {};
		reverse(ans.begin(), ans.end()); /* get finishing order */
		return ans;
	}
};
