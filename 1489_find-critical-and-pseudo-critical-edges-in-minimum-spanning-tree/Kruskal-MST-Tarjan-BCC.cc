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
    const int m = edges.size();
    map<int, vector<int>> sorted_edges; /* for Kruskal's algorithm */
    for (int edge_id = 0; edge_id < m; ++edge_id) {
      const int weight = edges[edge_id][2];
      sorted_edges[weight].push_back(edge_id);
    }

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
      vector<vector<int>> connections;
      for (int edge_id : edge_ids) {
        const int group_u = ds.FindSet(edges[edge_id][0]);
        const int group_v = ds.FindSet(edges[edge_id][1]);
        if (group_u != group_v) {
          MST_edge_ids.insert(edge_id);
          connections.push_back({group_u, group_v, edge_id});
        }
      }

      const auto critical_edge_ids = criticalConnections(connections);
      for (int edge_id : critical_edge_ids) {
        ans[0].push_back(edge_id);
        MST_edge_ids.erase(edge_id);
      }
      for (int edge_id : MST_edge_ids) ans[1].push_back(edge_id);

      /* Perform Kruskal's algorithm as usual */
      for (int edge_id : edge_ids) {
        const int group_u = ds.FindSet(edges[edge_id][0]);
        const int group_v = ds.FindSet(edges[edge_id][1]);
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
  vector<int> criticalConnections(const vector<vector<int>>& connections) {
    unordered_map<int, unordered_map<int, int>> adj_lists;
    for (const auto& connection : connections) {
      const int u = connection[0], v = connection[1], edge_id = connection[2];
      if (adj_lists[u].count(v) == 0)
        adj_lists[u][v] = adj_lists[v][u] = edge_id;
      else /* all duplicate edges are non-critical */
        adj_lists[u][v] = adj_lists[v][u] = -1;
    }

    vector<int> ret;
    unordered_map<int, int> low; /* for Tarjan's BCC algorithm */
    int timestamp = 0;

    using F = function<void(int, int)>;
    F dfs_visit = [&](int u, int parent) {
      const int discovery_time = ++timestamp;
      low[u] = discovery_time;

      for (const auto& adj : adj_lists[u]) {
        const int v = adj.first, edge_id = adj.second;
        if (v == parent) continue;
        if (!low[v]) {
          dfs_visit(v, u);
          if (discovery_time < low[v] && edge_id != -1) ret.push_back(edge_id);
        }
        low[u] = min(low[u], low[v]);
      }
    };

    for (const auto& it : adj_lists) {
      const int u = it.first;
      if (!low[u]) dfs_visit(u, -1);
    }

    return ret;
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
