class Solution {
public:
	/* time: O(n) time, space: O(n) */
	vector<int> preorderTraversal(const TreeNode* root) {
		if (!root)
			return {};
		vector<int> ans;
		stack<const TreeNode*> discovered;
		discovered.push(root);
		while (!discovered.empty()) {
			root = discovered.top(), discovered.pop();
			ans.push_back(root->val);
			if (root->right)
				discovered.push(root->right);
			if (root->left)
				discovered.push(root->left);
		}
		return ans;
	}
};
