class MorrisTraversal {
private:
	TreeNode dummy;
	TreeNode *curr;
	void nextInorder() {
		if (!curr)
			return;
		curr = curr->right;
		while (curr && curr->left) {
			TreeNode *pred = curr->left;
			while (pred->right && pred->right != curr)
				pred = pred->right;
			if (pred->right) {
				pred->right = NULL;
				break;
			}
			pred->right = curr, curr = curr->left;
		}
	}
public:
	MorrisTraversal(TreeNode *root) : dummy(-1), curr(&dummy) {
		dummy.right = root, nextInorder();
	}
	bool hasNext() const {
		return curr;
	}
	TreeNode *next() {
		TreeNode *prev = curr;
		nextInorder();
		return prev;
	}
};

class Solution {
private:
	static bool isSameNode(const TreeNode *p, const TreeNode *q) {
		return (!p && !q) || (p && q && p->val == q->val);
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	static bool isSameTree(TreeNode *p, TreeNode *q) {
		MorrisTraversal P(p), Q(q);
		bool ans = true;
		while (P.hasNext() && Q.hasNext()) {
			p = P.next(), q = Q.next();
			if (!isSameNode(p, q) || !isSameNode(p->left, q->left) || !isSameNode(p->right, q->right))
				ans = false;
		}
		while (P.hasNext())
			ans = false, p = P.next();
		while (Q.hasNext())
			ans = false, q = Q.next();
		return ans;
	}
};
