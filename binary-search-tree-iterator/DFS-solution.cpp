class BSTIterator {
private:
	using T = const TreeNode*;
	T p;
	stack<T> succ;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack itself) */
	BSTIterator(T root) : p(root) {}

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count stack itself) */
	int next() {
		if (!hasNext())
			return -1; /* failed */
		p = succ.top(), succ.pop();
		const int val = p->val;
		p = p->right;
		return val;
	}

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count stack itself) */
	bool hasNext() {
		while (p)
			succ.push(p), p = p->left;
		return !succ.empty();
	}
};
