class Solution {
private:
	typedef const TreeNode* T;
	typedef function<bool(T, T)> F;
public:
	/* time: O(n), space: O(n) */
	bool isSymmetric(const TreeNode* root) {
		if (!root)
			return true;
		/* This is exactly the same problem as LeetCode 100 - Same Tree */
		F dfs = [&](auto p, auto q) {
			if (!p && !q)
				return true;
			if (!p && q || p && !q || p->val != q->val)
				return false;
			return dfs(p->left, q->right) && dfs(p->right, q->left);
		};
		return dfs(root->left, root->right);
	}
};
