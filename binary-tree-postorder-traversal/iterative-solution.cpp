class Solution {
public:
	/* time: O(n), space: O(n) */
	vector<int> postorderTraversal(const TreeNode* root) {
		vector<int> ans;
		stack<const TreeNode*> succ; /* store successors to mimic threaded binary trees */
		const TreeNode* prev = NULL;
		while (root || !succ.empty())
			if (root)
				succ.push(root), root = root->left;
			else {
				root = succ.top();
				if (root->right && root->right != prev) {
					root = root->right;
					continue;
				}
				succ.pop();
				ans.push_back(root->val), prev = root, root = NULL;
			}
		return ans;
	}
};
