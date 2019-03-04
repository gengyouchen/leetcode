class Solution {
public:
	/* time: O(n), space: O(1) */
	TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) {
		while (root) {
			if (p->val < root->val && q->val < root->val)
				root = root->left;
			else if (p->val > root->val && q->val > root->val)
				root = root->right;
			else
				break;
		}
		return root;
	}
};
