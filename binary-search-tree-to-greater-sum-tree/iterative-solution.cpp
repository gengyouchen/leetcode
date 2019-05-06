class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		TreeNode *p = root;
		stack<TreeNode*> pred;
		while (p || !pred.empty()) {
			if (p) {
				pred.push(p), p = p->right;
			} else {
				p = pred.top(), pred.pop();
				sum += p->val, p->val = sum;
				p = p->left;
			}
		}
		return root;
	}
};
