class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) {
		TreeNode *ans = NULL;
		int depth = 1, minDepth = INT_MAX, nFound = 0;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 *     LeetCode 104 - Maximum Depth of Binary Tree
		 *     LeetCode 111 - Minimum Depth of Binary Tree
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
			if (nFound < 2) {
				if (root == p || root == q) {
					if (!ans)
						ans = root, minDepth = depth;
					++nFound;
				}
				if (ans && depth < minDepth)
					ans = root, minDepth = depth;
			}
			root = root->right, ++depth;
		}
		return ans;
	}
};
