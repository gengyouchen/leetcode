class Solution {
private:
	typedef function<void(const TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	vector<int> postorderTraversal(const TreeNode* root) {
		vector<int> ans;
		F dfs = [&](auto p) {
			if (p) {
				dfs(p->left);
				dfs(p->right);
				ans.push_back(p->val);
			}
		};
		dfs(root);
		return ans;
	}
};
