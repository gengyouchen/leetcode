class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		const int n = preorder.size();
		int i = 0, j = 0;

		using F = function<TreeNode*(const TreeNode*)>;
		F construct = [&](auto succ) {
			if (i == n || succ && inorder[j] == succ->val)
				return (TreeNode *)NULL;

			auto curr = new TreeNode(preorder[i++]);
			curr->left = construct(curr), ++j, curr->right = construct(succ);
			return curr;
		};

		return construct(NULL);
	}
};
