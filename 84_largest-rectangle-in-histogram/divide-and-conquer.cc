class Solution {
 public:
  /*
   * time: O(n * log(n)), space: O(n), where n = # of bars
   *
   * See also:
   *     85. Maximal Rectangle
   *   1504. Count Submatrices With All Ones
   */
  int largestRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    SegmentTree segTree(heights);

    auto maxArea = [&](const auto& maxArea, int L, int R) -> int {
      int ret = 0;
      if (L <= R) {
        int mid = segTree.rangeMinQuery(L, R);
        ret = heights[mid] * (R - L + 1);
        ret = max(ret, maxArea(maxArea, L, mid - 1));
        ret = max(ret, maxArea(maxArea, mid + 1, R));
      }
      return ret;
    };
    return maxArea(maxArea, 0, n - 1);
  }

 private:
  class SegmentTree {
   public:
    SegmentTree(const vector<int>& A) {
      int n = A.size();
      int n_leaves = 1;
      while (n_leaves < n) n_leaves *= 2;
      T.resize(n_leaves * 2);

      for (int i = 0; i < n_leaves; ++i)
        T[n_leaves + i] = {i < n ? A[i] : INT_MAX, i};

      for (int x = n_leaves - 1; x >= 0; --x)
        T[x] = min(T[getLeftChild(x)], T[getRightChild(x)]);
    }

    int rangeMinQuery(int i, int j) {
      int n_leaves = T.size() / 2, x = n_leaves + i, y = n_leaves + j;
      auto ret = min(T[x], T[y]);
      while (getParent(x) != getParent(y)) {
        if (hasRightSibling(x)) ret = min(ret, T[getRightSibling(x)]);
        x = getParent(x);

        if (hasLeftSibling(y)) ret = min(ret, T[getLeftSibling(y)]);
        y = getParent(y);
      }
      return ret.second;
    }

   private:
    vector<pair<int, int>> T;
    int getParent(int x) { return x / 2; }
    int getLeftChild(int x) { return x * 2; }
    int getRightChild(int x) { return x * 2 + 1; }
    int getLeftSibling(int x) { return x - 1; }
    int getRightSibling(int x) { return x + 1; }
    bool hasLeftSibling(int x) { return x % 2 == 1; }
    bool hasRightSibling(int x) { return x % 2 == 0; }
  };
};
