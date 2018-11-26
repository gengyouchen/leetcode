class Solution {
private:
	typedef TreeNode* T;
	typedef function<void(T, int)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* sortedArrayToBST(const vector<int>& nums) {
		if (nums.empty())
			return NULL;

		/* Imagine that we have a complete binary tree with n nodes */
		const int n = nums.size();
		auto L = [&](T p, int i) { if (!p->left && i * 2 <= n) p->left = new TreeNode(0); return p->left; };
		auto R = [&](T p, int i) { if (!p->right && i * 2 + 1 <= n) p->right = new TreeNode(0); return p->right; };

		T root = new TreeNode(0), ans = root;
		int i = 1;
		auto it = nums.begin();
		F dfs = [&](auto p, int i) {
			if (p) {
				dfs(L(p, i), i * 2);
				p->val = *it++;
				dfs(R(p, i), i * 2 + 1);
			}
		};
		dfs(root, 1);
		return ans;
	}
};
