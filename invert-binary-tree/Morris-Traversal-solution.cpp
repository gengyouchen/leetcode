class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	TreeNode* invertTree(TreeNode* root) {
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 145 - Binary Tree Postorder Traversal
		 */
		auto invertRightSpine = [](auto x) {
			while (x)
				swap(x->right, x->left), x = x->left;
		};
		TreeNode dummy(0);
		dummy.left = root, root = &dummy;
		while (root) {
			if (root->left) {
				auto pred = root->left;
				while (pred->right && pred->right != root)
					pred = pred->right;
				if (!pred->right) {
					pred->right = root;
					root = root->left;
					continue;
				}
				pred->right = NULL;
				invertRightSpine(root->left);
			}
			root = root->right;
		}
		return dummy.left;
	}
};
