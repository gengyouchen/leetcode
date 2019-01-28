class BSTIterator {
private:
	TreeNode *root, *ans;
	stack<TreeNode*> succ;
	void nextAns() {
		ans = NULL;
		while ((root || !succ.empty()) && !ans) {
			if (root) {
				succ.push(root), root = root->left;
			} else {
				root = succ.top(), succ.pop();
				ans = root, root = root->right;
			}
		}
	}
public:
	/* time: O(1) amortized, space: O(h), where h is the height of the tree */
	BSTIterator(TreeNode* root) : root(root) { nextAns(); }

	/* time: O(1) amortized, space: O(h), where h is the height of the tree */
	int next() {
		const int val = ans->val;
		nextAns();
		return val;
	}

	/* time: O(1), space: O(1) */
	bool hasNext() { return ans; }
};
