class Solution {
public:
	/* time: O(n), space: O(n) */
	void recoverTree(TreeNode* root) {
		TreeNode *prev = NULL, *wrong1 = NULL, *wrong2 = NULL;
		stack<TreeNode*> succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.push(root), root = root->left;
			else {
				root = succ.top(), succ.pop();
				if (prev && prev->val >= root->val) {
					if (!wrong1)
						wrong1 = prev;
					wrong2 = root;
				}
				prev = root, root = root->right;
			}
		swap(wrong1->val, wrong2->val);
	}
};
