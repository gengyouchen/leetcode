class Solution {
private:
	static bool isLeafNode(const TreeNode *x) {
		return x && !x->left && !x->right;
	};
public:
	/* time: O(n), space: O(n) */
	static int minDepth(const TreeNode* root) {
		int ans = INT_MAX;
		stack<pair<const TreeNode*, int>> S;
		if (root)
			S.emplace(root, 1);
		while (!S.empty()) {
			const int depth = S.top().second;
			root = S.top().first, S.pop();
			if (isLeafNode(root))
				ans = min(ans, depth);
			if (root->right)
				S.emplace(root->right, depth + 1);
			if (root->left)
				S.emplace(root->left, depth + 1);
		}
		return (ans == INT_MAX) ? 0 : ans;
	}
};
