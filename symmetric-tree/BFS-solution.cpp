class Solution {
private:
	static bool isSameNode(const TreeNode *p, const TreeNode *q) {
		return (!p && !q) || (p && q && p->val == q->val);
	}
	static bool isMirrowedTree(const TreeNode *p, const TreeNode *q) {
		queue<const TreeNode*> P, Q;
		if (!isSameNode(p, q))
			return false;
		if (p)
			P.push(p), Q.push(q);
		while (!P.empty()) {
			p = P.front(), q = Q.front(), P.pop(), Q.pop();
			if (!isSameNode(p->left, q->right) || !isSameNode(p->right, q->left))
				return false;
			if (p->left)
				P.push(p->left), Q.push(q->right);
			if (p->right)
				P.push(p->right), Q.push(q->left);
		}
		return true;
	}
public:
	/* time: O(n), space: O(n) */
	static bool isSymmetric(const TreeNode *root) {
		return !root || isMirrowedTree(root->left, root->right);
	}
};
