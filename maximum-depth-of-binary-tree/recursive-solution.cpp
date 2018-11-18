class Solution {
private:
	typedef const TreeNode* T;
	typedef function<void(T, int)> F;
public:
	/* time: O(n), space: O(n) */
	int maxDepth(const TreeNode* root) {
		if (!root)
			return 0;
		int ans = 0;
		F dfs = [&](auto p, int depth) {
			if (p) {
				dfs(p->left, depth + 1);
				ans = max(ans, depth);
				dfs(p->right, depth + 1);
			}
		};
		dfs(root, 1);
		return ans;
	}
};
