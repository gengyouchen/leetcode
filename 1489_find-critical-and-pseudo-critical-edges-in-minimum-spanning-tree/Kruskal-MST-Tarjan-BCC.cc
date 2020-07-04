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
    for (const auto& [weight, edge_ids] : sorted_edges) {
      /*
       * When Kruskal's algorithm handles mutiple edges with the same weight,
       *   the edges which are allowed to be in a MST (minimum spanning tree)
       *   are the edges connecting two existing connected components.
       *
       * By using these MST-allowed edges to construct a new undirected graph,
       *   where each vertex represents a existing connected components,
       *   we can know:
       *   1. bridges: critical edges
       *   2. non-bridges: pseudo-critical edges
       *
       * To find bridges in an undirected graph, we use Tarjan's BCC algorithm
       *   modified from 1192. Critical Connections in a Network
       */
      unordered_set<int> allowed_edge_ids;
      list<array<int, 3>> connections;
      for (int i : edge_ids) {
        int u = edges[i][0], v = edges[i][1];
        if (ds.FindSet(u) != ds.FindSet(v)) {
          allowed_edge_ids.insert(i);
          connections.push_back({ds.FindSet(u), ds.FindSet(v), i});
        }
      }

      auto critical_edge_ids = criticalConnections(connections);
      for (int i : critical_edge_ids) {
        ans[0].push_back(i);
        allowed_edge_ids.erase(i);
      }
      for (int i : allowed_edge_ids) ans[1].push_back(i);

      /* Perform Kruskal's algorithm as usual */
      for (int i : edge_ids) {
        int u = edges[i][0], v = edges[i][1];
        if (ds.FindSet(u) != ds.FindSet(v)) ds.Union(u, v);
      }
    }
    return ans;
  }

 private:
  /*
   * Modified the solution from 1192. Critical Connections in a Network:
   *   1. Discretize vertex IDs to make sure O(|V| + |E|) is just O(|E|)
   *   2. Treat duplicate edges as non-critical edges
   */
  list<int> criticalConnections(const list<array<int, 3>>& connections) {
    unordered_map<int, unordered_map<int, int>> adj_lists;
    for (const auto& [u, v, edge_id] : connections) {
      if (adj_lists[u].count(v) > 0)
        adj_lists[u][v] = adj_lists[v][u] = -1; /* duplicate */
      else
        adj_lists[u][v] = adj_lists[v][u] = edge_id;
    }

    list<int> critical_edge_ids;
    unordered_map<int, int> low; /* for Tarjan's BCC algorithm */
    int timestamp = 0;

    auto dfs = [&](const auto& dfs, int u, int predecessor) -> void {
      int discovery_time = low[u] = ++timestamp;

      for (const auto& [v, edge_id] : adj_lists[u]) {
        if (v == predecessor) continue;
        if (!low[v]) /* not yet visited */ {
          dfs(dfs, v, u);
          if (discovery_time < low[v]) /* found a bridge */ {
            if (edge_id != -1) /* not duplicate */
              critical_edge_ids.push_back(edge_id);
          }
        }
        low[u] = min(low[u], low[v]);
      }
    };

    for (const auto& [u, adj_list] : adj_lists) {
      if (!low[u]) /* not yet visited */
        dfs(dfs, u, -1);
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
