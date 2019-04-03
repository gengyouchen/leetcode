class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* invertTree(TreeNode *root) {
		queue<TreeNode*> Q;
		if (root)
			Q.push(root);
		while (!Q.empty()) {
			TreeNode *p = Q.front();
			Q.pop();
			swap(p->left, p->right);
			if (p->left)
				Q.push(p->left);
			if (p->right)
				Q.push(p->right);
		}
		return root;
	}
};
