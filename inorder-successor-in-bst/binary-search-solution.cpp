class Solution {
public:
	/* time: O(h), space: O(1), where h = log(n) if BST is balanced */
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		TreeNode *ans = NULL;
		while (root) {
			if (p->val < root->val)
				ans = root, root = root->left;
			else
				root = root->right;
		}
		return ans;
	}
};
