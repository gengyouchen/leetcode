class Solution {
private:
	typedef const TreeNode* T;
	typedef stack<T> S;
	T getNext(T& root, S& succ, bool reversed = false) {
		auto L = [&](T x) { return reversed ? x->right : x->left; };
		auto R = [&](T x) { return reversed ? x->left : x->right; };

		T ans = NULL;
		while ((root || !succ.empty()) && !ans)
			if (root)
				succ.push(root), root = L(root);
			else {
				root = succ.top(), succ.pop();
				ans = root, root = R(root);
			}
		return ans;
	}
	T getPrevious(T& root, S& succ) { return getNext(root, succ, true); }
public:
	/* time: O(n), space: O(n) */
	bool isSymmetric(const TreeNode* root) {
		if (!root)
			return true;
		/* This is exactly the same problem as LeetCode 100 - Same Tree */
		bool ans = true;
		S pSucc, qSucc; /* store successors to mimic threaded binary trees */
		T p = root->left, q = root->right, i = getNext(p, pSucc), j = getPrevious(q, qSucc);
		while (i && j) {
			ans = ans &&
				(i->val == j->val) &&
				(i->left && j->right && i->left->val == j->right->val || !i->left && !j->right) &&
				(i->right && j->left && i->right->val == j->left->val || !i->right && !j->left);
			i = getNext(p, pSucc), j = getPrevious(q, qSucc);
		}
		while (i)
			ans = false, i = getNext(p, pSucc);
		while (j)
			ans = false, j = getPrevious(q, qSucc);
		return ans;
	}
};
