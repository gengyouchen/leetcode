class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		/* Use the "Morris Traversal" method to mimic the threaded binary tree */
		while (root) {
			if (root->left) {
				/* check if root->left has the successor link to the root */
				auto pred = root->left;
				while (pred->right && pred->right != root)
					pred = pred->right;

				if (!pred->right) {
					/* case 1: no successor link (i.e. not yet visied root->left) */
					pred->right = root; /* create the successor link */
					root = root->left;
					continue;
				}

				/* case 2: found successor link (i.e. already visied root->left) */
				pred->right = NULL; /* remove the successor link */
			}
			ans.push_back(root->val);
			root = root->right;
		}
		return ans;
	}
};
