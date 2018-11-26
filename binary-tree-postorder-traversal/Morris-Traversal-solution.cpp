class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		/* Use the "Morris Traversal" method to mimic the threaded binary tree */
		auto reverseRightSpine = [](auto x) {
			TreeNode* out = NULL;
			while (x) {
				auto it = x; /* it = x.top() */
				x = x->right; /* x.pop() */
				it->right = out, out = it; /* out.push(it) */
			}
			return out;
		};
		TreeNode dummy(0);
		dummy.left = root, root = &dummy;
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

				/* output root->left's right spine in reversed order */
				reverseRightSpine(root->left);
				for (auto it = pred; it; it = it->right)
					ans.push_back(it->val);
				reverseRightSpine(pred);
			}
			root = root->right;
		}
		return ans;
	}
};
