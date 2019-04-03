class Solution {
public:
	/* time: O(n), space: O(n) */
	int maxDepth(const TreeNode *root) {
		int ans = 0;
		queue<const TreeNode*> Q;
		if (root)
			Q.push(root);
		for (int depth = 1; !Q.empty(); ++depth) {
			for (int i = Q.size() - 1; i >= 0; --i) {
				root = Q.front(), Q.pop();
				ans = max(ans, depth);
				if (root->left)
					Q.push(root->left);
				if (root->right)
					Q.push(root->right);
			}
		}
		return ans;
	}
};
