class Solution {
public:
	/* time: O(n), space: O(n) */
	static int removeStones(const vector<vector<int>>& stones) {
		const int n = stones.size();
		unordered_map<int, vector<int>> row2indices, col2indices;
		for (int i = 0; i < n; ++i) {
			const int row = stones[i][0], col = stones[i][1];
			row2indices[row].push_back(i), col2indices[col].push_back(i);
		}

		vector<bool> visited(n);
		auto visit = [&](int src) {
			queue<int> Q;
			Q.push(src), visited[src] = true;
			while (!Q.empty()) {
				const int u = Q.front(), row = stones[u][0], col = stones[u][1];
				Q.pop();
				for (int v : row2indices[row]) {
					if (!visited[v])
						Q.push(v), visited[v] = true;
				}
				for (int v : col2indices[col]) {
					if (!visited[v])
						Q.push(v), visited[v] = true;
				}
			}
		};

		int nGroups = 0;
		for (int u = 0; u < n; ++u) {
			if (!visited[u])
				nGroups++, visit(u);
		}
		return n - nGroups;
	}
};
