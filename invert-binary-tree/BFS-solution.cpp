class Solution {
public:
	/* time: O(n), space: O(n) */
	TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> q;
		if (root)
			q.push(root);
		while (!q.empty()) {
			TreeNode *p = q.front();
			q.pop();
			swap(p->left, p->right);
			if (p->left)
				q.push(p->left);
			if (p->right)
				q.push(p->right);
		}
		return root;
	}
};
