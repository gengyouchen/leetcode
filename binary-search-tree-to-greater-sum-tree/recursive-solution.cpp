class Solution {
private:
	typedef function<void(TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	static TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		F dfs = [&](auto p) {
			if (p) {
				dfs(p->right);
				sum += p->val, p->val = sum;
				dfs(p->left);
			}
		};
		dfs(root);
		return root;
	}
};
