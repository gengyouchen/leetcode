class Solution {
public:
	/* time: O(n), space: O(n) */
	bool isValidBST(const TreeNode* root) {
		const TreeNode* prev = NULL;
		stack<const TreeNode*> succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.push(root), root = root->left;
			else {
				root = succ.top(), succ.pop();
				if (prev && prev->val >= root->val)
					return false;
				prev = root, root = root->right;
			}
		return true;
	}
};
