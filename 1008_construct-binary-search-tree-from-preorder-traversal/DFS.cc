class Solution {
 public:
  /*
   * time: O(n), space: O(n), where n = # of nodes
   *
   * See also:
   *   105. Construct Binary Tree from Preorder and Inorder Traversal
   *   106. Construct Binary Tree from Inorder and Postorder Traversal
   *   889. Construct Binary Tree from Preorder and Postorder Traversal
   */
  TreeNode* bstFromPreorder(const vector<int>& preorder) {
    int n = preorder.size(), i = 0;
    auto dfs = [&](const auto& dfs, const TreeNode* successor) -> TreeNode* {
      if (i == n || successor && successor->val < preorder[i]) return nullptr;

      auto curr = new TreeNode(preorder[i++]);
      curr->left = dfs(dfs, curr);
      curr->right = dfs(dfs, successor);
      return curr;
    };
    return dfs(dfs, nullptr);
  }
};
