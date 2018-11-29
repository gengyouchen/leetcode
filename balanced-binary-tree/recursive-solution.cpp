class Solution {
private:
	typedef function<int(const TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	bool isBalanced(const TreeNode* root) {
		bool ans = true;
		F height = [&](auto root) {
			if (!root)
				return 0;
			const int L = height(root->left), R = height(root->right);
			ans = ans && (R - L <= 1) && (R - L >= -1);
			return 1 + max(L, R);
		};
		height(root);
		return ans;
	}
};
