class Solution {
public:
	/* time: O(n), space: O(n) */
	static vector<int> findMinHeightTrees(int n, const vector<vector<int>>& edges) {
		vector<vector<int>> adjList(n);
		vector<int> inDegree(n);
		for (const auto& edge : edges) {
			const int u = edge[0], v = edge[1];
			adjList[u].push_back(v), ++inDegree[v];
			adjList[v].push_back(u), ++inDegree[u];
		}

		vector<int> ans;
		queue<int> Q;
		for (int i = 0; i < n; ++i) {
			if (inDegree[i] <= 1)
				Q.push(i);
		}
		while (!Q.empty()) {
			ans.clear();
			for (int i = Q.size(); i > 0; --i) {
				const int u = Q.front();
				Q.pop(), ans.push_back(u);
				for (int v : adjList[u]) {
					if (--inDegree[v] == 1)
						Q.push(v);
				}
			}
		}
		return ans;
	}
};
