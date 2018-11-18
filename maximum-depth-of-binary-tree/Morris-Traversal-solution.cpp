class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int ans = 0, depth = 1;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
		while (root) {
			if (root->left) {
				auto pred = root->left;
				int deltaDepth = 1; /* between root and pred */
				while (pred->right && pred->right != root)
					pred = pred->right, ++deltaDepth;
				if (!pred->right) {
					pred->right = root;
					root = root->left, ++depth;
					continue;
				}
				pred->right = NULL;
				--depth; /* rollback to pred's depth */
				depth -= deltaDepth;
			}
			ans = max(ans, depth);
			root = root->right, ++depth;
		}
		return ans;
	}
};
