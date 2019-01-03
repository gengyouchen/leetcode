class Solution {
private:
	typedef function<void(const TreeNode*, int)> F;
public:
	/* time: O(n), space: O(n) */
	int sumNumbers(const TreeNode* root) {
		if (!root)
			return 0;
		int ans = 0;
		F dfs = [&](auto root, int parent) {
			const int val = parent * 10 + root->val;
			if (!root->left && !root->right) {
				ans += val;
			} else {
				if (root->left)
					dfs(root->left, val);
				if (root->right)
					dfs(root->right, val);
			}
		};
		dfs(root, 0);
		return ans;
	}
};
