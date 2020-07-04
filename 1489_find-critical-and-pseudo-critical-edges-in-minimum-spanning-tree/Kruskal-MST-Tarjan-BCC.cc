class Solution {
 public:
  /*
   * time: O(m * log(m)), space: O(n + m),
   *   where n = # of vertice, m = # of edges
   *
   * See also:
   *   1192. Critical Connections in a Network
   */
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(
      int n, vector<vector<int>>& edges) {
    int m = edges.size();
    map<int, list<int>> sorted_edges;
    for (int i = 0; i < m; ++i) sorted_edges[edges[i][2]].push_back(i);

    vector<vector<int>> ans(2);
    DisjointSet ds(n);
    for (auto it = sorted_edges.begin(); it != sorted_edges.end(); ++it) {
      const auto& edge_ids = it->second;

      /*
       * When Kruskal's algorithm handles mutiple edges with the same weight,
       *   the edges which are allowed to be in a MST (minimum spanning tree)
       *   are the edges connecting two distinct groups.
       *
       * By using these MST-allowed edges to construct a new undirected graph,
       *   where each vertex represents a distinct group, we can know:
       *   1. bridges: critical edges
       *   2. non-bridges: pseudo-critical edges
       */
      unordered_set<int> MST_edge_ids;
      list<vector<int>> connections;
      for (int i : edge_ids) {
        int group_u = ds.FindSet(edges[i][0]);
        int group_v = ds.FindSet(edges[i][1]);
        if (group_u != group_v) {
          MST_edge_ids.insert(i);
          connections.push_back({group_u, group_v, i});
        }
      }

      auto critical_edge_ids = criticalConnections(connections);
      for (int i : critical_edge_ids) {
        ans[0].push_back(i);
        MST_edge_ids.erase(i);
      }
      for (int i : MST_edge_ids) ans[1].push_back(i);

      /* Perform Kruskal's algorithm as usual */
      for (int i : edge_ids) {
        int group_u = ds.FindSet(edges[i][0]);
        int group_v = ds.FindSet(edges[i][1]);
        if (group_u != group_v) ds.Union(group_u, group_v);
      }
    }
    return ans;
  }

 private:
  /*
   * Modified the solution from 1192. Critical Connections in a Network:
   *   1. Discretize vertex IDs to make sure O(|V| + |E|) is just O(|E|)
   *   2. Treat duplicate connections as non-critical edge
   */
  list<int> criticalConnections(const list<vector<int>>& connections) {
    unordered_map<int, unordered_map<int, int>> adj_lists;
    for (auto& connection : connections) {
      int u = connection[0], v = connection[1], edge_id = connection[2];
      if (adj_lists[u].count(v)) /* duplicate edges */
        adj_lists[u][v] = adj_lists[v][u] = -1;
      else
        adj_lists[u][v] = adj_lists[v][u] = edge_id;
    }

    list<int> critical_edge_ids;
    unordered_map<int, int> low; /* for Tarjan's BCC algorithm */
    int timestamp = 0;

    auto dfs = [&](const auto& dfs, int u, int predecessor) -> void {
      int discovery_time = ++timestamp;
      low[u] = discovery_time;

      for (auto& adj : adj_lists[u]) {
        int v = adj.first, edge_id = adj.second;
        if (v == predecessor) continue;
        if (!low[v]) {
          dfs(dfs, v, u);
          if (discovery_time < low[v]) /* found a bridge */
            if (edge_id != -1) critical_edge_ids.push_back(edge_id);
        }
        low[u] = min(low[u], low[v]);
      }
    };

    for (auto& adj_list : adj_lists) {
      int u = adj_list.first;
      if (!low[u]) dfs(dfs, u, -1);
    }
    return critical_edge_ids;
  }

  class DisjointSet {
   public:
    DisjointSet(int n) : p(n), rank(n) { iota(p.begin(), p.end(), 0); }

    int FindSet(int x) {
      if (p[x] != x) p[x] = FindSet(p[x]);
      return p[x];
    }

    void Union(int x, int y) {
      x = FindSet(x), y = FindSet(y);
      if (x != y) {
        if (rank[x] > rank[y]) {
          p[y] = x;
        } else {
          p[x] = y;
          if (rank[x] == rank[y]) ++rank[y];
        }
      }
    }

   private:
    vector<int> p, rank;
  };
};
