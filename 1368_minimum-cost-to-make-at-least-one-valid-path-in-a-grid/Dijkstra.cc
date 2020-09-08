class Solution {
 public:
  /* time: O(m*n * log(m*n)), space: O(m*n) */
  int minCost(const vector<vector<int>>& grid) {
    const vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int m = grid.size(), n = grid[0].size();

    /* Dijkstra algorithm */
    vector<vector<int>> d(m, vector<int>(n, INT_MAX));
    set<pair<int, pair<int, int>>> pq;
    d[0][0] = 0;
    pq.insert({0, {0, 0}});

    while (!pq.empty()) {
      const auto [y0, x0] = pq.begin()->second;
      pq.erase(pq.begin());

      for (int i = 0; i < 4; ++i) {
        const int y1 = y0 + dirs[i].first, x1 = x0 + dirs[i].second;
        if (y1 >= m || y1 < 0 || x1 >= n || x1 < 0) continue;

        const int weight = (i + 1 == grid[y0][x0]) ? 0 : 1;
        if (d[y0][x0] + weight < d[y1][x1]) {
          pq.erase({d[y1][x1], {y1, x1}});
          d[y1][x1] = d[y0][x0] + weight;
          pq.insert({d[y1][x1], {y1, x1}});
        }
      }
    }
    return d[m - 1][n - 1];
  }
};
