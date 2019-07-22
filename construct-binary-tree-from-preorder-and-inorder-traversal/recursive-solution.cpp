class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		const int m = preorder.size(), n = inorder.size();
		int i = 0, j = 0;

		using F = function<TreeNode*(const TreeNode*)>;
		F dfs = [&](auto succ) {
			if (j == n || succ && inorder[j] == succ->val)
				return (TreeNode *)NULL;

			auto curr = new TreeNode(preorder[i++]);
			curr->left = dfs(curr), ++j, curr->right = dfs(succ);
			return curr;
		};

		return dfs(NULL);
	}
};
