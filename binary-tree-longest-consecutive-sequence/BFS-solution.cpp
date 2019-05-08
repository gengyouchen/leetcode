class Solution {
private:
	static bool isConsecutive(const TreeNode *parent, const TreeNode *child) {
		return parent->val + 1 == child->val;
	}
public:
	/* time: O(n), space: O(n) */
	static int longestConsecutive(const TreeNode* root) {
		int ans = 0;
		queue<pair<const TreeNode*, int>> Q;
		if (root)
			Q.emplace(root, 1);
		while (!Q.empty()) {
			const int len = Q.front().second;
			root = Q.front().first, Q.pop(), ans = max(ans, len);
			if (root->left)
				Q.emplace(root->left, isConsecutive(root, root->left) ? len + 1 : 1);
			if (root->right)
				Q.emplace(root->right, isConsecutive(root, root->right) ? len + 1 : 1);
		}
		return ans;
	}
};
