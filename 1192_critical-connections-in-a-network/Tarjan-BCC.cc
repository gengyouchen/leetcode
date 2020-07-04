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
    vector<list<int>> adj_lists(n);
    for (auto& connection : connections) {
      int u = connection[0], v = connection[1];
      adj_lists[u].push_back(v);
      adj_lists[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<int> low(n); /* for Tarjan's BCC algorithm */
    int timestamp = 0;

    auto dfs = [&](const auto& dfs, int u, int predecessor) -> void {
      int discovery_time = ++timestamp;
      low[u] = discovery_time;

      for (int v : adj_lists[u]) {
        if (v == predecessor) continue;
        if (!low[v]) {
          dfs(dfs, v, u);
          if (discovery_time < low[v]) /* found a bridge */
            ans.push_back({u, v});
        }
        low[u] = min(low[u], low[v]);
      }
    };

    for (int i = 0; i < n; ++i)
      if (!low[i]) dfs(dfs, i, -1);

    return ans;
  }
};
