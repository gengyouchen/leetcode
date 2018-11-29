class Solution {
private:
	typedef const TreeNode* T;
	typedef function<void(T, int)> F;
public:
	/* time: O(n), space: O(n) */
	bool hasPathSum(const TreeNode* root, int sum) {
		if (!root)
			return 0;
		bool ans = false;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		F dfs = [&](auto p, int depth) {
			if (p) {
				depth += p->val;
				dfs(p->left, depth);
				if (isLeaf(p))
					ans = ans || (depth == sum);
				dfs(p->right, depth);
			}
		};
		dfs(root, 0);
		return ans;
	}
};
