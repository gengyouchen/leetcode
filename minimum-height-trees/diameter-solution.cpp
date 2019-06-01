class Solution {
public:
	/* time: O(n), space: O(n) */
	static vector<int> findMinHeightTrees(int n, const vector<vector<int>>& edges) {
		if (n <= 0)
			return {};
		vector<vector<int>> adjList(n);
		for (const auto& edge : edges) {
			const int u = edge[0], v = edge[1];
			adjList[u].push_back(v), adjList[v].push_back(u);
		}
		/*
		 * See CLRS textbook 22.2 Exercise 8 (find the diameter of a tree in O(n) time)
		 *
		 * Assume the diameter of a tree is end1 <-> end2
		 * If we do BFS from any node X in the tree, the farthest node F must be end1 (or end2)
		 *
		 * <Proof>
		 * Case 1. If X is on the diameter...
		 *         Proof by contradiction: assume F is not end1 (farthest end)
		 *         --> d(X, F) > d(X, end1)
		 *         --> d(end2, X) + d(X, F) > d(end2, X) + d(X, end1)
		 *         --> d(end2, F) > d(end2, end1)
		 *         --> The diameter should not be end1 <-> end2, which is a contradiction!
		 *
		 * Case 2. If X is NOT on the diameter, and the path "X to F" overlaps the diameter...
		 *         Proof using case 1's result:
		 *         Let node Y is on the path "X to F", and is also on the diameter.
		 *         The farthest node started from node Y should be end1/end2.
		 *
		 * Case 3. If X is NOT on the diameter, and the path "X to F" does NOT overlap the diameter...
		 *         Let node P is on the path "X to F", and node Q is on the diameter, such that
		 *         the path "P to Q" does NOT overlap the path "X to F" and the diameter, except P and Q itself.
		 *         Proof by contradiction: assume F is not end1 (farthest end)
		 *         d(X, F) > d(X, end1)
		 *         --> d(X, P) + d(P, F) > d(X, P) + d(P, Q) + d(Q, end1)
		 *         --> d(P, F) > d(P, Q) + d(Q, end1)
		 *         --> d(end2, Q) + d(P, F) > d(P, Q) + d(end2, Q) + d(Q, end1)
		 *         --> d(end2, Q) + d(P, F) > d(P, Q) + d(end2, end1)
		 *         --> d(end2, Q) + d(Q, P) + d(P, F) > 2 * d(P, Q) + d(end2, end1)
		 *         --> d(end2, F) > 2 * d(P, Q) + d(end2, end1)
		 *         --> d(end2, F) > d(end2, end1)
		 *         --> The diameter should not be end1 <-> end2, which is a contradiction!
		 */
		vector<int> d(n), parent(n);
		auto bfs = [&](int src) {
			fill(d.begin(), d.end(), INT_MAX);
			fill(parent.begin(), parent.end(), -1);

			queue<int> Q;
			d[src] = 0, parent[src] = -1, Q.push(src);
			while (!Q.empty()) {
				const int u = Q.front();
				Q.pop();
				for (int v : adjList[u]) {
					if (d[v] == INT_MAX)
						d[v] = d[u] + 1, parent[v] = u, Q.push(v);
				}
			}
		};
		bfs(0);
		const int end1 = max_element(d.begin(), d.end()) - d.begin();
		bfs(end1);
		const int end2 = max_element(d.begin(), d.end()) - d.begin();
		vector<int> diameter;
		for (int x = end2; x != -1; x = parent[x])
			diameter.push_back(x);

		/* To minimize the height, select the middle point of the diameter as the root */
		if (diameter.size() % 2)
			return {diameter[diameter.size() / 2]};
		else
			return {diameter[diameter.size() / 2 - 1], diameter[diameter.size() / 2]};
	}
};
