class Solution {
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

		vector<int> nIndegree(numCourses, 0);
		for (const auto& adjList : adjLists) {
			for (int u : adjList)
				++nIndegree[u];
		}

		queue<int> Q;
		for (int i = 0; i < numCourses; ++i) {
			if (!nIndegree[i])
				Q.push(i);
		}

		int nFinished = 0;
		while (!Q.empty()) {
			const int u = Q.front();
			Q.pop();
			++nFinished;
			for (int v : adjLists[u]) {
				if (!--nIndegree[v])
					Q.push(v);
			}
		}
		return (nFinished == numCourses);
	}
};
