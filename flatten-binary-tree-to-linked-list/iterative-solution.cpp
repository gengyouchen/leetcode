class Solution {
private:
	typedef function<TreeNode*(TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	void flatten(TreeNode* root) {
		if (!root)
			return;
		F dfs = [&](auto root) {
			if (!root->left && !root->right)
				return root;
			if (!root->left)
				return dfs(root->right);
			if (!root->right) {
				swap(root->left, root->right);
				return dfs(root->right);
			}
			auto leftTail = dfs(root->left), rightTail = dfs(root->right);
			leftTail->right = root->right, root->right = root->left, root->left = NULL;
			return rightTail;
		};
		dfs(root);
	}
};
