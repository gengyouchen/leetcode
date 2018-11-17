class Solution {
public:
	/* time: O(n) time, space: O(1) auxiliary (i.e. does not count input & output itself) */
	void recoverTree(TreeNode* root) {
		TreeNode *prev = NULL, *wrong1 = NULL, *wrong2 = NULL;
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
			if (prev && prev->val >= root->val) {
				if (!wrong1)
					wrong1 = prev;
				wrong2 = root;
			}
			prev = root, root = root->right;
		}
		swap(wrong1->val, wrong2->val);
	}
};
