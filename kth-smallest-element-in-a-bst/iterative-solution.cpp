class Solution {
public:
	/* time: O(n), space: O(n) */
	int kthSmallest(const TreeNode* root, int k) {
		int ans, idx = 1;
		stack<const TreeNode*> succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty()) {
			if (root) {
				succ.push(root), root = root->left;
			} else {
				root = succ.top(), succ.pop();
				if (idx++ == k)
					ans = root->val;
				root = root->right;
			}
		}
		return ans;
	}
};
