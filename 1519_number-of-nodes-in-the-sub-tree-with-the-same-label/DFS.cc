class Solution {
 public:
  /* time: O(n), space: O(n), where n = # of nodes */
  vector<int> countSubTrees(int n, const vector<vector<int>>& edges,
                            const string& labels) {
    vector<list<int>> adjLists(n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      adjLists[u].push_back(v);
      adjLists[v].push_back(u);
    }

    vector<int> ans(n);
    int count[26] = {};
    auto dfs = [&](const auto& dfs, int u, int parent) -> void {
      int c = labels[u] - 'a', before = count[c]++;
      for (int v : adjLists[u])
        if (v != parent) dfs(dfs, v, u);

      int after = count[c];
      ans[u] = after - before;
    };
    dfs(dfs, 0, -1);
    return ans;
  }
};
