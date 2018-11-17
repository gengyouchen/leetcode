class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	bool isValidBST(TreeNode* root) {
		bool ans = true;
		TreeNode* prev = NULL;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
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
			}
			ans = ans && (!prev || prev->val < root->val), prev = root;
			root = root->right;
		}
		return ans;
	}
};
