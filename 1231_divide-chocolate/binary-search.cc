class Solution {
 public:
  /*
   * time: O(n * log(n)), extra space: O(1), where n = # of chunks
   *
   * See also:
   *   410. Split Array Largest Sum
   *   875. Koko Eating Bananas
   */
  int maximizeSweetness(const vector<int>& sweetness, int K) {
    auto lowest_true = [&](const auto& cond, int low, int high) -> int {
      while (low < high) {
        const int mid = low + (high - low) / 2;
        if (cond(mid))
          high = mid;
        else
          low = mid + 1;
      }
      return low;
    };

    auto cannot_cut = [&](int min_piece_size) -> bool {
      int n_pieces = 0, curr_piece_size = 0;
      for (int chunk : sweetness) {
        curr_piece_size += chunk;
        if (curr_piece_size >= min_piece_size) {
          ++n_pieces;
          curr_piece_size = 0;
        }
        if (n_pieces >= K + 1) return false;
      }
      return true;
    };

    const int total = accumulate(sweetness.begin(), sweetness.end(), 0);
    return lowest_true(cannot_cut, 1, total + 1) - 1;
  }
};
