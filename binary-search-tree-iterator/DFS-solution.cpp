class BSTIterator {
private:
	const TreeNode *root;
	stack<const TreeNode*> succ;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack itself) */
	BSTIterator(const TreeNode* root) : root(root) { }

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count stack itself) */
	int next() {
		if (!hasNext())
			return -1; /* failed */
		root = succ.top(), succ.pop();
		const int val = root->val;
		root = root->right;
		return val;
	}

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count stack itself) */
	bool hasNext() {
		while (root)
			succ.push(root), root = root->left;
		return !succ.empty();
	}
};
