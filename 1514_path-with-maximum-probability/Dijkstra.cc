class Solution {
 public:
  /*
   * time: O((n + m) * log(n)), space: O(n + m),
   *   where n = # of vertices, m = # of edges
   */
  double maxProbability(int n, const vector<vector<int>>& edges,
                        const vector<double>& succProb, int start, int end) {
    vector<list<pair<int, double>>> adjLists(n);
    int m = edges.size();
    for (int i = 0; i < m; ++i) {
      int u = edges[i][0], v = edges[i][1];
      double w = -log2(succProb[i]);
      adjLists[u].emplace_back(v, w);
      adjLists[v].emplace_back(u, w);
    }

    vector<double> d(n, DBL_MAX);
    set<pair<double, int>> Q;
    d[start] = 0;
    Q.emplace(d[start], start);

    while (!Q.empty()) {
      int u = Q.begin()->second;
      Q.erase(Q.begin());
      for (const auto& [v, w] : adjLists[u]) {
        if (d[u] + w < d[v]) {
          Q.erase({d[v], v});
          d[v] = d[u] + w;
          Q.emplace(d[v], v);
        }
      }
    }

    if (d[end] == DBL_MAX) return 0;
    return 1 / exp2(d[end]);
  }
};
