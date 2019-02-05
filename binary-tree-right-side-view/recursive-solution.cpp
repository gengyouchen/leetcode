class Solution {
private:
	typedef const TreeNode* T;
	typedef function<void(T, int)> F;
public:
	/* time: O(n), space: O(n) */
	vector<int> rightSideView(const TreeNode* root) {
		if (!root)
			return {};
		vector<int> ans;
		F dfs = [&](auto p, int depth) {
			if (p) {
				dfs(p->left, depth + 1);
				while (ans.size() < depth)
					ans.push_back(0);
				ans[depth - 1] = p->val;
				dfs(p->right, depth + 1);
			}
		};
		dfs(root, 1);
		return ans;
	}
};
