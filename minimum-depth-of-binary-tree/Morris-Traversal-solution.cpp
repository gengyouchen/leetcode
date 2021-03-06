class MorrisTraversal {
private:
	TreeNode dummy;
	TreeNode *curr;
	int depth = 0;
	void nextInorder() {
		if (!curr)
			return;
		curr = curr->right, ++depth;
		while (curr && curr->left) {
			TreeNode *pred = curr->left;
			int deltaDepth = 1;
			while (pred->right && pred->right != curr)
				pred = pred->right, ++deltaDepth;
			if (pred->right) {
				pred->right = NULL, depth -= deltaDepth + 1;
				break;
			}
			pred->right = curr, curr = curr->left, ++depth;
		}
	}
public:
	MorrisTraversal(TreeNode *root) : dummy(-1), curr(&dummy) {
		dummy.right = root, nextInorder();
	}
	bool hasNext() const {
		return curr;
	}
	pair<TreeNode*, int> next() {
		TreeNode *prev = curr;
		const int prevDepth = depth;
		nextInorder();
		return {prev, prevDepth};
	}
};

class Solution {
private:
	static bool isLeafNode(const TreeNode *x) {
		return x && !x->left && !x->right;
	};
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	static int minDepth(TreeNode *root) {
		int ans = INT_MAX;
		MorrisTraversal it(root);
		while (it.hasNext()) {
			pair<TreeNode*, int> curr = it.next();
			if (isLeafNode(curr.first))
				ans = min(ans, curr.second);
		}
		return (ans == INT_MAX) ? 0 : ans;
	}
};
