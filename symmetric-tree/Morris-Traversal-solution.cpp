class Solution {
private:
	typedef TreeNode* T;
	T getNext(T& root, bool reversed = false) {
		auto L = [&](T x) -> T& { return reversed ? x->right : x->left; };
		auto R = [&](T x) -> T& { return reversed ? x->left : x->right; };

		T ans = NULL;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
		while (root && !ans) {
			if (L(root)) {
				T pred = L(root);
				while (R(pred) && R(pred) != root)
					pred = R(pred);
				if (!R(pred)) {
					R(pred) = root;
					root = L(root);
					continue;
				}
				R(pred) = NULL;
			}
			ans = root;
			root = R(root);
		}
		return ans;
	}
	T getPrevious(T& root) { return getNext(root, true); }
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		/* This is exactly the same problem as LeetCode 100 - Same Tree */
		bool ans = true;
		T p = root->left, q = root->right, i = getNext(p), j = getPrevious(q);
		while (i && j) {
			ans = ans &&
				(i->val == j->val) &&
				(i->left && j->right && i->left->val == j->right->val || !i->left && !j->right) &&
				(i->right && j->left && i->right->val == j->left->val || !i->right && !j->left);
			i = getNext(p), j = getPrevious(q);
		}
		while (i)
			ans = false, i = getNext(p);
		while (j)
			ans = false, j = getPrevious(q);
		return ans;
	}
};
