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
			stack<int> S;
			S.push(src);
			while (!S.empty()) {
				const int u = S.top(), row = stones[u][0], col = stones[u][1];
				S.pop();
				for (int v : row2indices[row]) {
					if (!visited[v])
						S.push(v), visited[v] = true;
				}
				for (int v : col2indices[col]) {
					if (!visited[v])
						S.push(v), visited[v] = true;
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
