class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		int ans = INT_MAX, depth = 1, prevDepth = 0;
		TreeNode *prev = NULL;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
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
			if (isLeaf(prev))
				ans = min(ans, prevDepth);
			prev = root, prevDepth = depth;
			root = root->right, ++depth;
		}
		if (isLeaf(prev))
			ans = min(ans, prevDepth);
		return ans;
	}
};
