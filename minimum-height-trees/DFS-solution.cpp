class Solution {
private:
	typedef function<void(int, int)> F1;
	typedef function<void(int, int, int)> F2;
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

		vector<int> downLength(n), downLength2nd(n);
		F1 findDownLength = [&](int u, int parent) {
			downLength[u] = downLength2nd[u] = 1;
			for (int v : adjList[u]) {
				if (v != parent) {
					findDownLength(v, u);
					if (downLength[u] < downLength[v] + 1)
						downLength2nd[u] = downLength[u], downLength[u] = downLength[v] + 1;
					else if (downLength2nd[u] < downLength[v] + 1)
						downLength2nd[u] = downLength[v] + 1;
				}
			}
		};
		findDownLength(0, -1);

		vector<int> height(n);
		F2 findHeight = [&](int u, int parent, int upLength) {
			height[u] = max(upLength, downLength[u]);
			for (int v : adjList[u]) {
				if (v != parent) {
					if (downLength[u] == downLength[v] + 1)
						findHeight(v, u, max(upLength, downLength2nd[u]) + 1);
					else
						findHeight(v, u, max(upLength, downLength[u]) + 1);
				}
			}
		};
		findHeight(0, -1, 1);

		vector<int> ans;
		const int minHeight = *min_element(height.begin(), height.end());
		for (int i = 0; i < n; ++i) {
			if (height[i] == minHeight)
				ans.push_back(i);
		}
		return ans;
	}
};
