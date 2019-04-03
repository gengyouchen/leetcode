class Solution {
public:
	/* time: O(n), space: O(n) */
	int maxDepth(const TreeNode *root) {
		int ans = 0;
		stack<pair<const TreeNode*, int>> S;
		if (root)
			S.emplace(root, 1);
		while (!S.empty()) {
			const int depth = S.top().second;
			root = S.top().first, S.pop();
			ans = max(ans, depth);
			if (root->right)
				S.emplace(root->right, depth + 1);
			if (root->left)
				S.emplace(root->left, depth + 1);
		}
		return ans;
	}
};
