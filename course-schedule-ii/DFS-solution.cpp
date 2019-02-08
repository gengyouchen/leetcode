class Solution {
private:
	typedef function<bool(int)> F;
	enum Color { WHITE, GRAY, BLACK };
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
		vector<int> color(numCourses, WHITE);

		F dfs = [&](int u) {
			color[u] = GRAY;
			for (int v : adjLists[u]) {
				if (color[v] == GRAY) /* u->v is a back edge */
					return false;
				if (color[v] == WHITE) /* u->v is a tree edge */ {
					if (!dfs(v))
						return false;
				}
			}
			color[u] = BLACK;
			ans.push_back(u);
			return true;
		};

		for (int i = 0; i < numCourses; ++i) {
			if (color[i] == WHITE) {
				if (!dfs(i))
					return {};
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
