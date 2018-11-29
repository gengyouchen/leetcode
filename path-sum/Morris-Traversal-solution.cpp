class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return 0;
		bool ans = false;
		int depth = root->val, prevDepth = 0;
		TreeNode *prev = NULL;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 *     LeetCode 104 - Maximum Depth of Binary Tree
		 *     LeetCode 111 - Minimum Depth of Binary Tree
		 */
		while (root) {
			if (root->left) {
				auto pred = root->left;
				int deltaDepth = pred->val; /* between root and pred */
				while (pred->right && pred->right != root)
					pred = pred->right, deltaDepth += pred->val;
				if (!pred->right) {
					pred->right = root;
					root = root->left, depth += root->val;
					continue;
				}
				pred->right = NULL;
				depth -= root->val; /* rollback to pred's depth */
				depth -= deltaDepth;
			}
			if (isLeaf(prev))
				ans = ans || (prevDepth == sum);
			prev = root, prevDepth = depth;
			root = root->right, depth += (root ? root->val : 0);
		}
		if (isLeaf(prev))
			ans = ans || (prevDepth == sum);
		return ans;
	}
};
