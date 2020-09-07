class Solution {
 public:
  /*
   * time: O(n * log(n)), space: O(n), where n = tickets.size()
   * Can be improved to O(n) time if we implement counting sort
   *
   * See also:
   *   753. Cracking the Safe
   */
  vector<string> findItinerary(const vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> adjLists;
    for (const auto& ticket : tickets)
      adjLists[ticket[0]].emplace_back(ticket[1]);

    for (auto& [u, adjList] : adjLists) {
      /* [TODO] use counting sort instead of quick sort */
      sort(adjList.begin(), adjList.end(), greater<string>());
    }

    /* Hierholzer algorithm */
    vector<string> ans;
    auto dfs = [&](const auto& dfs, const string& u) -> void {
      auto& adjList = adjLists[u];
      while (!adjList.empty()) {
        const auto v = adjList.back();
        adjList.pop_back();
        dfs(dfs, v);
      }
      ans.push_back(u);
    };
    dfs(dfs, "JFK");
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
