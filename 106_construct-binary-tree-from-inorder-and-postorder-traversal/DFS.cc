class Solution {
 public:
  /*
   * time: O(n), space: O(n), where n = # of nodes
   *
   * See also:
   *    105. Construct Binary Tree from Preorder and Inorder Traversal
   *    889. Construct Binary Tree from Preorder and Postorder Traversal
   *   1008. Construct Binary Search Tree from Preorder Traversal
   */
  TreeNode* buildTree(const vector<int>& inorder,
                      const vector<int>& postorder) {
    int n = inorder.size(), i = n - 1, j = n - 1;
    auto dfs = [&](const auto& dfs, TreeNode* predecessor) -> TreeNode* {
      if (j < 0 || predecessor && predecessor->val == inorder[j])
        return nullptr;

      auto curr = new TreeNode(postorder[i--]);
      curr->right = dfs(dfs, curr);
      --j;
      curr->left = dfs(dfs, predecessor);
      return curr;
    };
    return dfs(dfs, nullptr);
  }
};
