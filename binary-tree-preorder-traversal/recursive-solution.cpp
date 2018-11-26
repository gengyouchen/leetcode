class Solution {
private:
	typedef function<void(const TreeNode*)> F;
public:
	/* time: O(n) time, space: O(n) */
	vector<int> preorderTraversal(const TreeNode* root) {
		vector<int> ans;
		F dfs = [&](auto p) {
			if (p) {
				ans.push_back(p->val);
				dfs(p->left);
				dfs(p->right);
			}
		};
		dfs(root);
		return ans;
	}
};
