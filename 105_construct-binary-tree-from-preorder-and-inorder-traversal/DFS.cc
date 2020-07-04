class Solution {
 public:
  /*
   * time: O(n), space: O(n), where n = # of nodes
   *
   * See also:
   *    106. Construct Binary Tree from Inorder and Postorder Traversal
   *    889. Construct Binary Tree from Preorder and Postorder Traversal
   *   1008. Construct Binary Search Tree from Preorder Traversal
   */
  TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    int n = preorder.size(), i = 0, j = 0;
    auto dfs = [&](const auto& dfs, const TreeNode* successor) -> TreeNode* {
      if (j == n || successor && successor->val == inorder[j]) return nullptr;

      auto curr = new TreeNode(preorder[i++]);
      curr->left = dfs(dfs, curr);
      ++j;
      curr->right = dfs(dfs, successor);
      return curr;
    };
    return dfs(dfs, nullptr);
  }
};
