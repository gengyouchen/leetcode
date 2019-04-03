class MorrisTraversal {
private:
	bool reversed;
	TreeNode* &left(TreeNode *x) {
		return reversed ? x->right : x->left;
	}
	TreeNode* &right(TreeNode *x) {
		return reversed ? x->left : x->right;
	}
	TreeNode dummy;
	TreeNode *curr;
	void nextInorder() {
		if (!curr)
			return;
		curr = right(curr);
		while (curr && left(curr)) {
			TreeNode *pred = left(curr);
			while (right(pred) && right(pred) != curr)
				pred = right(pred);
			if (right(pred)) {
				right(pred) = NULL;
				break;
			}
			right(pred) = curr, curr = left(curr);
		}
	}
public:
	MorrisTraversal(TreeNode *root, bool reversed) : dummy(-1), curr(&dummy), reversed(reversed) {
		right(&dummy) = root, nextInorder();
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
	static bool isMirrowedTree(TreeNode *p, TreeNode *q) {
		MorrisTraversal P(p, false), Q(q, true);
		bool ans = true;
		while (P.hasNext() && Q.hasNext()) {
			p = P.next(), q = Q.next();
			if (!isSameNode(p, q) || !isSameNode(p->left, q->right) || !isSameNode(p->right, q->left))
				ans = false;
		}
		while (P.hasNext())
			ans = false, p = P.next();
		while (Q.hasNext())
			ans = false, q = Q.next();
		return ans;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	static bool isSymmetric(const TreeNode *root) {
		return !root || isMirrowedTree(root->left, root->right);
	}
};
