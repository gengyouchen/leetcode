class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		auto p = root;
		while (p) {
			if (p->right) {
				auto succ = p->right;
				while (succ->left && succ->left != p)
					succ = succ->left;
				if (!succ->left) {
					succ->left = p, p = p->right;
					continue;
				}
				succ->left = NULL;
			}
			sum += p->val, p->val = sum, p = p->left;
		}
		return root;
	}
};
