class MinCostFlow {
private:
	struct Edge { int cost = 0, capacity = 0; };
	vector<unordered_map<int, Edge>> adjLists;
public:
	MinCostFlow(int n) : adjLists(n) { }
	void setEdge(int u, int v, int cost) {
		adjLists[u][v].capacity = 1, adjLists[u][v].cost = cost, adjLists[v][u].cost = -cost;
	}

	int minCost(int src, int sink) {
		const int n = adjLists.size();

		vector<bool> changed(n);
		queue<int> q;
		vector<int> d(n), parent(n);

		/* Use SPFA to handle negative edges in O(VE) time */
		auto SPFA = [&]() {
			fill(parent.begin(), parent.end(), -1);
			fill(d.begin(), d.end(), INT_MAX);

			d[src] = 0, q.push(src), changed[src] = true;

			while (!q.empty()) {
				const int u = q.front();
				q.pop(), changed[u] = false;

				for (const auto& it : adjLists[u]) {
					const int v = it.first;
					const auto& edge = it.second;
					if (edge.capacity > 0 && d[u] + edge.cost < d[v]) {
						d[v] = d[u] + edge.cost, parent[v] = u;
						if (!changed[v])
							q.push(v), changed[v] = true;
					}
				}
			}
			return d[sink] < INT_MAX;
		};

		/* Use Ford-Fulkerson method in O(V*E*F), where F is the max flow */
		int totalCost = 0;
		while (SPFA()) {
			int f = INT_MAX;
			for (int v = sink, u = parent[v]; u != -1; v = u, u = parent[u])
				f = min(f, adjLists[u][v].capacity);

			for (int v = sink, u = parent[v]; u != -1; v = u, u = parent[u])
				adjLists[u][v].capacity -= f, adjLists[v][u].capacity += f, totalCost += adjLists[u][v].cost * f;
		}
		return totalCost;
	}
};

class Solution {
public:
	/*
	 * time: O(V*E*F) ~= O((m*n)^2), space: O(V+E) ~= O(m*n),
	 * where V = n + m + 2, E = n * m + n + m, F = n
	 */
	static int assignBikes(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
		const int n = workers.size(), m = bikes.size(), src = n + m, sink = n + m + 1;
		MinCostFlow g(n + m + 2);
		for (int i = 0; i < n; ++i)
			g.setEdge(src, i, 0);
		for (int i = 0; i < m; ++i)
			g.setEdge(n + i, sink, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				g.setEdge(i, n + j, abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]));
		}
		return g.minCost(src, sink);
	}
};
