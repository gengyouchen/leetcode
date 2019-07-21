class Solution {
public:
	/* time: O(n), space: O(n) */
	static int countComponents(int n, const vector<vector<int>>& edges) {
		vector<vector<int>> adjLists(n);
		for (const auto& edge : edges) {
			const int u = edge[0], v = edge[1];
			adjLists[u].push_back(v);
			adjLists[v].push_back(u);
		}

		vector<bool> visited(n);
		auto dfsVisit = [&](int src) {
			stack<int> s;
			s.push(src), visited[src] = true;
			while (!s.empty()) {
				const int u = s.top();
				s.pop();
				for (int v : adjLists[u]) {
					if (!visited[v])
						s.push(v), visited[v] = true;
				}
			}
		};

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				++ans, dfsVisit(i);
		}
		return ans;
	}
};
