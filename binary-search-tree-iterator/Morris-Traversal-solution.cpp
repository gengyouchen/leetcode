class BSTIterator {
private:
	TreeNode *root, *ans;
	void nextAns() {
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
		ans = NULL;
		while (root && !ans) {
			if (root->left) {
				auto pred = root->left;
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
	}
public:
	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count tree itself) */
	BSTIterator(TreeNode* root) : root(root) { nextAns(); }

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count tree itself) */
	int next() {
		const int val = ans->val;
		nextAns();
		return val;
	}

	/* time: O(1), space: O(1) */
	bool hasNext() { return ans; }
};
