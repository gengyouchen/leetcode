class Solution {
private:
	static bool isLeafNode(const TreeNode *x) {
		return x && !x->left && !x->right;
	};
public:
	/* time: O(n), space: O(n) */
	static int minDepth(const TreeNode *root) {
		int ans = INT_MAX;
		queue<const TreeNode*> Q;
		if (root)
			Q.push(root);
		for (int depth = 1; !Q.empty(); ++depth) {
			for (int i = Q.size() - 1; i >= 0; --i) {
				root = Q.front(), Q.pop();
				if (isLeafNode(root))
					ans = min(ans, depth);
				if (root->left)
					Q.push(root->left);
				if (root->right)
					Q.push(root->right);
			}
		}
		return (ans == INT_MAX) ? 0 : ans;
	}
};
