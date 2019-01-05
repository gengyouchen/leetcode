class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	int sumNumbers(TreeNode* root) {
		if (!root)
			return 0;
		int ans = 0, depth = 1, prevDepth = 0;
		long val = 0, prevVal = 0;
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
				int deltaVal = 10, deltaDepth = 1; /* between root and pred */
				while (pred->right && pred->right != root)
					deltaVal *= 10, pred = pred->right, ++deltaDepth;
				if (!pred->right) {
					pred->right = root;
					val = val * 10 + root->val, root = root->left, ++depth;
					continue;
				}
				pred->right = NULL;
				val /= 10, --depth; /* rollback to pred's depth */
				val /= deltaVal, depth -= deltaDepth;
			}
			if (isLeaf(prev))
				ans += prevVal * 10 + prev->val;
			prev = root, prevVal = val;
			val = val * 10 + root->val, root = root->right, ++depth;
		}
		if (isLeaf(prev))
			ans += prevVal * 10 + prev->val;
		return ans;
	}
};
