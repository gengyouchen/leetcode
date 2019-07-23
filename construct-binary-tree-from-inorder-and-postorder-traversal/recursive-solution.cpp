class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		const int n = inorder.size();
		int i = n - 1, j = n - 1;

		using F = function<TreeNode*(const TreeNode*)>;
		F construct = [&](auto pred) {
			if (i == -1 || pred && inorder[j] == pred->val)
				return (TreeNode *)NULL;

			auto curr = new TreeNode(postorder[i--]);
			curr->right = construct(curr), --j, curr->left = construct(pred);
			return curr;
		};

		return construct(NULL);
	}
};
