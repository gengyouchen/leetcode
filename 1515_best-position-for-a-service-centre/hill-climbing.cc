class Solution {
 public:
  /*
   * time: O(w * h * n), space: O(1), assuming # of iterations < 50,
   *   where (w, h) = map size, n = # of customers
   */
  double getMinDistSum(const vector<vector<int>>& positions) {
    /*
     * For each customer position,
     *   the distance from an input centre to it is a convex function.
     *
     * Because the sum of convex functions remains convex,
     *   the sum of distances to all customers is also a convex function.
     *
     * We can just find a local minimum because it will be the global minimum.
     */
    using Point = complex<double>;
    auto distSum = [&](const Point& centre) -> double {
      double dist = 0;
      for (const auto& position : positions)
        dist += abs(centre - Point(position[0], position[1]));
      return dist;
    };

    Point u(0, 0);
    for (const auto& position : positions) u += Point(position[0], position[1]);
    u /= positions.size();

    /*
     * For simplicity, we use the hill climbing method with fixed 4 directions,
     *   which is good enough for all testcases.
     *
     * It may fail if a lower value only happen in a direction between them.
     * A better way is implementing the Gradient Descent method.
     */
    Point dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    double step = 1.0;
    for (int k = 0; k < 50; ++k) {
      bool is_min = false;
      while (!is_min) {
        is_min = true;
        for (const auto& dir : dirs) {
          auto v = u + dir * step;
          if (distSum(u) > distSum(v)) {
            u = v;
            is_min = false;
          }
        }
      }
      step /= 2;
    }
    return distSum(u);
  }
};
