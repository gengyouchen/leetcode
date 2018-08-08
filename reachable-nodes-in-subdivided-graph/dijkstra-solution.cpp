class Solution {
public:
	/* time: O((|edges| + N) * log(N)), space: O(|edges| + N) */
	int reachableNodes(vector<vector<int>>& edges, int M, int N) {
		auto adjList = vector<vector<pair<int, int>>>(N);
		for (auto& i : edges) {
			int u = i[0], v = i[1], w = 1 + i[2];
			adjList[u].emplace_back(v, w);
			adjList[v].emplace_back(u, w);
		}

		auto d = vector<int>(N, INT_MAX);
		auto used = vector<unordered_map<int, int>>(N);
		auto pq = set<pair<int, int>>();
		d[0] = 0;
		pq.emplace(d[0], 0);

		while (!pq.empty()) {
			auto it = pq.begin();
			int u = it->second;
			pq.erase(it);

			for (auto& adj : adjList[u]) {
				int v = adj.first, w = adj.second;
				used[u][v] = min(M - d[u], w - 1);
				if (M - d[u] < w)
					continue; /* not able to reach v */

				if (d[v] > d[u] + w) {
					auto it = pq.find({d[v], v});
					if (it != pq.end())
						pq.erase(it);
					d[v] = d[u] + w;
					pq.emplace(d[v], v);
				}
			}
		}

		int ans = 0;
		for (auto i : d)
			if (i <= M)
				++ans;
		for (auto& i : edges) {
			int u = i[0], v = i[1], w = 1 + i[2];
			ans += min(used[u][v] + used[v][u], w - 1);
		}
		return ans;
	}
};
