class Solution {
private:
	typedef function<int(const TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	int maxPathSum(const TreeNode* root) {
		int ans = INT_MIN;
		F maxToRoot = [&](auto root) {
			if (!root)
				return 0;
			const int L = maxToRoot(root->left), R = maxToRoot(root->right);
			ans = max(ans, root->val + L + R);
			return max(0, root->val + max(L, R));
		};
		maxToRoot(root);
		return ans;
	}
};
