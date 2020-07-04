class Solution {
 public:
  /*
   * time: O(n), space: O(n), where n = # of nodes
   *
   * See also:
   *    105. Construct Binary Tree from Preorder and Inorder Traversal
   *    106. Construct Binary Tree from Inorder and Postorder Traversal
   *   1008. Construct Binary Search Tree from Preorder Traversal
   */
  TreeNode* constructFromPrePost(const vector<int>& pre,
                                 const vector<int>& post) {
    int n = pre.size(), i = 0, j = 0;
    auto dfs = [&](const auto& dfs, const TreeNode* parent) -> TreeNode* {
      if (j == n || parent && parent->val == post[j]) return nullptr;

      auto curr = new TreeNode(pre[i++]);
      curr->left = dfs(dfs, curr);
      curr->right = dfs(dfs, curr);
      ++j;
      return curr;
    };
    return dfs(dfs, nullptr);
  }
};
