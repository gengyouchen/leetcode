class Solution {
private:
	typedef function<void(TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* invertTree(TreeNode* root) {
		F dfs = [&](auto p) {
			if (p) {
				dfs(p->left);
				dfs(p->right);
				swap(p->left, p->right);
			}
		};
		dfs(root);
		return root;
	}
};
