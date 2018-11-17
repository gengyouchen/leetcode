class Solution {
private:
	typedef function<bool(const TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	bool isValidBST(const TreeNode* root) {
		const TreeNode* prev = NULL;
		F dfs = [&](auto p) {
			if (p) {
				if (!dfs(p->left))
					return false;
				if (prev && prev->val >= p->val)
					return false;
				prev = p;
				if (!dfs(p->right))
					return false;
			}
			return true;
		};
		return dfs(root);
	}
};
