class Solution {
 public:
  /*
   * time: O(n), space: O(n), where n = # of nodes
   *
   * See also:
   *   543. Diameter of Binary Tree
   */
  int diameter(const Node* root) {
    int ans = 0;
    auto dfs = [&](const auto& dfs, const Node* x) -> int {
      if (x) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        min_heap.push(0);
        min_heap.push(0);
        for (auto child : x->children) {
          min_heap.push(dfs(dfs, child));
          min_heap.pop();
        }

        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();

        ans = max(ans, a + b);
        return max(a, b) + 1;
      }
      return 0;
    };
    dfs(dfs, root);
    return ans;
  }
};
