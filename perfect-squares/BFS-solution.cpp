class Solution {
public:
	/* time: O(n ^ 1.5), space: O(n) */
	static int numSquares(int n) {
		vector<bool> visited(n + 1);
		queue<int> Q;
		Q.push(n), visited[n] = true;
		for (int depth = 0; !Q.empty(); ++depth) {
			for (int i = Q.size() - 1; i >= 0; --i) {
				const int u = Q.front();
				Q.pop();
				if (u == 0)
					return depth;
				for (int last = 1; last * last <= u; ++last) {
					const int v = u - last * last;
					if (!visited[v])
						Q.push(v), visited[v] = true;
				}
			}
		}
		return INT_MAX;
	}
};
