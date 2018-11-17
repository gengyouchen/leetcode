class Solution {
private:
	typedef function<void(const TreeNode*)> F;
public:
	/* time: O(n) time, space: O(n) auxiliary (i.e. does not count output itself) */
	vector<int> inorderTraversal(const TreeNode* root) {
		vector<int> ans;
		F dfs = [&](auto p) {
			if (p) {
				dfs(p->left);
				ans.push_back(p->val);
				dfs(p->right);
			}
		};
		dfs(root);
		return ans;
	}
};
