class Solution {
 public:
  /*
   * time: O(n + m), space: O(n + m),
   *   where n = # of servers, m = # of connections
   *
   * See also:
   *   1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
   */
  vector<vector<int>> criticalConnections(
      int n, const vector<vector<int>>& connections) {
    vector<vector<int>> adj_lists(n);
    for (const auto& connection : connections) {
      const int u = connection[0], v = connection[1];
      adj_lists[u].push_back(v);
      adj_lists[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<int> low(n); /* for Tarjan's BCC algorithm */
    int timestamp = 0;

    using F = function<void(int, int)>;
    F dfs_visit = [&](int u, int parent) {
      const int discovery_time = ++timestamp;
      low[u] = discovery_time;

      for (int v : adj_lists[u]) {
        if (v == parent) continue;
        if (!low[v]) {
          dfs_visit(v, u);
          if (discovery_time < low[v]) ans.push_back({u, v});
        }
        low[u] = min(low[u], low[v]);
      }
    };

    for (int i = 0; i < n; ++i)
      if (!low[i]) dfs_visit(i, -1);

    return ans;
  }
};
