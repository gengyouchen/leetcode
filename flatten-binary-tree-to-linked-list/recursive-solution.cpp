class Solution {
private:
	typedef function<TreeNode*(TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	void flatten(TreeNode* root) {
		F dfs = [&](auto root) {
			if (!root)
				return root;
			auto L = dfs(root->left), R = dfs(root->right);
			if (root->left)
				L->right = root->right, root->right = root->left, root->left = NULL;
			return R ? R : (L ? L : root);
		};
		dfs(root);
	}
};
