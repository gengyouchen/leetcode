class Solution {
public:
	/* time: O(n), space: O(n) */
	TreeNode* invertTree(TreeNode* root) {
		stack<TreeNode*> parents;
		TreeNode* prev = NULL;
		while (root || !parents.empty()) {
			if (root) {
				parents.push(root), root = root->left;
			} else {
				root = parents.top();
				if (root->right && root->right != prev) {
					root = root->right;
					continue;
				}
				swap(root->left, root->right), prev = root;
				parents.pop(), root = NULL;
			}
		}
		return prev;
	}
};
