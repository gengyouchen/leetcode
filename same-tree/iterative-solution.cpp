class Solution {
private:
	typedef const TreeNode* T;
	typedef stack<T> S;
	T getNext(T& root, S& succ) {
		T ans = NULL;
		while ((root || !succ.empty()) && !ans)
			if (root)
				succ.push(root), root = root->left;
			else {
				root = succ.top(), succ.pop();
				ans = root, root = root->right;
			}
		return ans;
	}
public:
	/* time: O(n), space: O(n) */
	bool isSameTree(const TreeNode* p, const TreeNode* q) {
		bool ans = true;
		S pSucc, qSucc; /* store successors to mimic threaded binary trees */
		T i = getNext(p, pSucc), j = getNext(q, qSucc);
		while (i && j) {
			ans = ans &&
				(i->val == j->val) &&
				(i->left && j->left && i->left->val == j->left->val || !i->left && !j->left) &&
				(i->right && j->right && i->right->val == j->right->val || !i->right && !j->right);
			i = getNext(p, pSucc), j = getNext(q, qSucc);
		}
		while (i)
			ans = false, i = getNext(p, pSucc);
		while (j)
			ans = false, j = getNext(q, qSucc);
		return ans;
	}
};
