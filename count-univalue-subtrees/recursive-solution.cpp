class Solution {
private:
	typedef function<bool(const TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	int countUnivalSubtrees(const TreeNode* root) {
		int ans = 0;
		F dfs = [&](auto p) {
			if (p) {
				const bool L = dfs(p->left), R = dfs(p->right);
				const bool ret = (!p->left || p->left->val == p->val && L) && (!p->right || p->right->val == p->val && R);
				if (ret)
					++ans;
				return ret;
			}
			return false;
		};
		dfs(root);
		return ans;
	}
};
