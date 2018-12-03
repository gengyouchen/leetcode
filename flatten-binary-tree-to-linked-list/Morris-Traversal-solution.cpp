class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void flatten(TreeNode* root) {
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
		while (root) {
			if (root->left) {
				auto pred = root->left;
				while (pred->right)
					pred = pred->right;
				pred->right = root->right, root->right = root->left, root->left = NULL;
			}
			root = root->right;
		}
	}
};
