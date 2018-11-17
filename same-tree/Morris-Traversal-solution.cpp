class Solution {
private:
	typedef TreeNode* T;
	T getNext(T& root) {
		T ans = NULL;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
		while (root && !ans) {
			if (root->left) {
				T pred = root->left;
				while (pred->right && pred->right != root)
					pred = pred->right;
				if (!pred->right) {
					pred->right = root;
					root = root->left;
					continue;
				}
				pred->right = NULL;
			}
			ans = root;
			root = root->right;
		}
		return ans;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool ans = true;
		T i = getNext(p), j = getNext(q);
		while (i && j) {
			ans = ans &&
				(i->val == j->val) &&
				(i->left && j->left && i->left->val == j->left->val || !i->left && !j->left) &&
				(i->right && j->right && i->right->val == j->right->val || !i->right && !j->right);
			i = getNext(p), j = getNext(q);
		}
		while (i)
			ans = false, i = getNext(p);
		while (j)
			ans = false, j = getNext(q);
		return ans;
	}
};
