class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* invertTree(TreeNode *root) {
		stack<TreeNode*> S;
		if (root)
			S.push(root);
		while (!S.empty()) {
			TreeNode *p = S.top();
			S.pop();
			swap(p->left, p->right);
			if (p->right)
				S.push(p->right);
			if (p->left)
				S.push(p->left);
		}
		return root;
	}
};
