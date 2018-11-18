class Solution {
private:
	typedef const TreeNode* T;
	typedef function<void(T, int)> F;
public:
	/* time: O(n), space: O(n) */
	int minDepth(const TreeNode* root) {
		if (!root)
			return 0;
		int ans = INT_MAX;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		F dfs = [&](auto p, int depth) {
			if (p) {
				dfs(p->left, depth + 1);
				if (isLeaf(p))
					ans = min(ans, depth);
				dfs(p->right, depth + 1);
			}
		};
		dfs(root, 1);
		return ans;
	}
};
