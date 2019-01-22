class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		TreeNode *ans = NULL, *sibling = NULL;
		while (root) {
			auto x = root; /* x = root.top() */
			root = root->left; /* root.pop() */

			x->left = sibling, sibling = x->right;
			x->right = ans, ans = x; /* ans.push(x) */
		}
		return ans;
	}
};
