class Solution {
 public:
  /* time: O(n), space: O(n), where n = # of nodes */
  int diameterOfBinaryTree(const TreeNode* root) {
    int ans = 0;
    auto dfs = [&](const auto& dfs, const TreeNode* x) -> int {
      if (x) {
        int L = dfs(dfs, x->left), R = dfs(dfs, x->right);
        ans = max(ans, L + R);
        return max(L, R) + 1;
      }
      return 0;
    };
    dfs(dfs, root);
    return ans;
  }
};
