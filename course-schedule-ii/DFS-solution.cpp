class Solution {
private:
	typedef function<bool(int)> F;
public:
	/*
	 * time: O(|V| + |E|), space: O(|V| + |E|)
	 * where |V| = numCourses, |E| = len(prerequisites)
	 */
	vector<int> findOrder(int numCourses, const vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> adjLists(numCourses);
		for (auto it : prerequisites) {
			const int u = it.second, v = it.first;
			adjLists[u].push_back(v);
		}

		vector<int> ans;
		vector<bool> onStack(numCourses, false), visited(numCourses, false);

		F dfs = [&](int u) {
			visited[u] = onStack[u] = true;
			for (int v : adjLists[u]) {
				if (onStack[v])
					return false; /* failed */
				if (!visited[v]) {
					if (!dfs(v))
						return false; /* failed */
				}
			}
			onStack[u] = false;
			ans.push_back(u);
			return true;
		};

		for (int i = 0; i < numCourses; ++i) {
			if (!visited[i]) {
				if (!dfs(i))
					return {}; /* failed */
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
