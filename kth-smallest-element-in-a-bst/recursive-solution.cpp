class Solution {
private:
	typedef function<void(const TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	int kthSmallest(const TreeNode* root, int k) {
		int ans, idx = 1;
		F dfs = [&](auto p) {
			if (p) {
				dfs(p->left);
				if (idx++ == k)
					ans = p->val;
				dfs(p->right);
			}
		};
		dfs(root);
		return ans;
	}
};
