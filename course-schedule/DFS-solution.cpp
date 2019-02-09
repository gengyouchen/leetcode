class Solution {
private:
	typedef function<bool(int)> F;
	enum Color { WHITE, GRAY, BLACK };
public:
	/*
	 * time: O(|V| + |E|), space: O(|V| + |E|)
	 * where |V| = numCourses, |E| = len(prerequisites)
	 */
	bool canFinish(int numCourses, const vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> adjLists(numCourses);
		for (auto it : prerequisites) {
			const int u = it.second, v = it.first;
			adjLists[u].push_back(v);
		}

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
			return true;
		};

		for (int i = 0; i < numCourses; ++i) {
			if (color[i] == WHITE) {
				if (!dfs(i))
					return false;
			}
		}
		return true;
	}
};
