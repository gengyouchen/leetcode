class Solution {
public:
	/* time: O(n), space: O(n) */
	vector<int> inorderTraversal(const TreeNode* root) {
		vector<int> ans;
		stack<const TreeNode*> succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.push(root), root = root->left;
			else {
				root = succ.top(), succ.pop();
				ans.push_back(root->val), root = root->right;
			}
		return ans;
	}
};
