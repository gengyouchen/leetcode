class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return {};
		vector<int> ans;
		int depth = 1;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 *     LeetCode 104 - Maximum Depth of Binary Tree
		 *     LeetCode 111 - Minimum Depth of Binary Tree
		 */
		while (root) {
			if (root->left) {
				auto pred = root->left;
				int deltaDepth = 1; /* between root and pred */
				while (pred->right && pred->right != root)
					pred = pred->right, ++deltaDepth;
				if (!pred->right) {
					pred->right = root;
					root = root->left, ++depth;
					continue;
				}
				pred->right = NULL;
				--depth; /* rollback to pred's depth */
				depth -= deltaDepth;
			}
			while (ans.size() < depth)
				ans.push_back(0);
			ans[depth - 1] = root->val;
			root = root->right, ++depth;
		}
		return ans;
	}
};
