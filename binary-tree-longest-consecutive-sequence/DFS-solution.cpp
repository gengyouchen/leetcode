class Solution {
private:
	static bool isConsecutive(const TreeNode *parent, const TreeNode *child) {
		return parent->val + 1 == child->val;
	}
public:
	/* time: O(n), space: O(n) */
	static int longestConsecutive(const TreeNode* root) {
		int ans = 0;
		stack<pair<const TreeNode*, int>> S;
		if (root)
			S.emplace(root, 1);
		while (!S.empty()) {
			const int len = S.top().second;
			root = S.top().first, S.pop(), ans = max(ans, len);
			if (root->right)
				S.emplace(root->right, isConsecutive(root, root->right) ? len + 1 : 1);
			if (root->left)
				S.emplace(root->left, isConsecutive(root, root->left) ? len + 1 : 1);
		}
		return ans;
	}
};
