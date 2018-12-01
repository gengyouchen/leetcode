class Solution {
public:
	/* time: O(n), space: O(n) */
	vector<int> postorderTraversal(const TreeNode* root) {
		vector<int> ans;
		stack<const TreeNode*> parents;
		const TreeNode* prev = NULL;
		while (root || !parents.empty())
			if (root)
				parents.push(root), root = root->left;
			else {
				root = parents.top();
				if (root->right && root->right != prev) {
					root = root->right;
					continue;
				}
				ans.push_back(root->val), prev = root;
				parents.pop(), root = NULL;
			}
		return ans;
	}
};
