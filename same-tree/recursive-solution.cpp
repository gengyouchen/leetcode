class Solution {
public:
	/* time: O(n), space: O(n) */
	bool isSameTree(const TreeNode* p, const TreeNode* q) {
		if (!p && !q)
			return true;
		if (!p && q || p && !q || p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
