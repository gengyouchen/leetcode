class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* bstFromPreorder(const vector<int>& preorder) {
		const int n = preorder.size();
		int i = 0;

		using F = function<TreeNode*(const TreeNode*)>;
		F build = [&](auto succ) {
			TreeNode *p = NULL;
			if (i == n)
				return p;
			if (succ && preorder[i] > succ->val)
				return p;
			p = new TreeNode(preorder[i++]), p->left = build(p), p->right = build(succ);
			return p;
		};

		return build(NULL);
	}
};
