class Solution {
public:
	/* time: O(n^2), space: O(n) */
	static int findCircleNum(const vector<vector<int>>& M) {
		const int n = M.size();
		vector<bool> visited(n);
		auto visit = [&](int src) {
			stack<int> S;
			S.push(src), visited[src] = true;
			while (!S.empty()) {
				const int u = S.top();
				S.pop();
				for (int v = 0; v < n; ++v) {
					if (M[u][v] && !visited[v])
						S.push(v), visited[v] = true;
				}
			}
		};

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				++ans, visit(i);
		}
		return ans;
	}
};
