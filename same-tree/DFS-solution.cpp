class Solution {
private:
	bool isSameNode(const TreeNode *p, const TreeNode *q) const {
		return (!p && !q) || (p && q && p->val == q->val);
	}
public:
	/* time: O(n), space: O(n) */
	bool isSameTree(const TreeNode *p, const TreeNode *q) const {
		stack<const TreeNode*> P, Q;
		if (!isSameNode(p, q))
			return false;
		if (p)
			P.push(p), Q.push(q);
		while (!P.empty()) {
			p = P.top(), q = Q.top(), P.pop(), Q.pop();
			if (!isSameNode(p->left, q->left) || !isSameNode(p->right, q->right))
				return false;
			if (p->right)
				P.push(p->right), Q.push(q->right);
			if (p->left)
				P.push(p->left), Q.push(q->left);
		}
		return true;
	}
};
