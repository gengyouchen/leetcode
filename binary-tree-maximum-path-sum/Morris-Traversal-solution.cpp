class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	int maxPathSum(TreeNode* root) {
		int ans = INT_MIN;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 145 - Binary Tree Postorder Traversal
		 */
		auto reverseRightSpine = [](auto x) {
			TreeNode* out = NULL;
			while (x) {
				auto it = x;
				x = x->right;
				it->right = out, out = it;
			}
			return out;
		};
		TreeNode dummy(0);
		dummy.left = root, root = &dummy;
		while (root) {
			if (root->left) {
				auto pred = root->left;
				while (pred->right && pred->right != root)
					pred = pred->right;
				if (!pred->right) {
					pred->right = root;
					root = root->left;
					continue;
				}
				pred->right = NULL;
				reverseRightSpine(root->left);
				TreeNode* rightChild = NULL;
				for (auto it = pred; it; rightChild = it, it = it->right) {
					/*
					 * Similar to the iterative DFS solution
					 * However, we use node i's value field
					 * to record the maxToRoot(root = node i)
					 * in order to achieve O(1) auxiliary space
					 *
					 * Warning:
					 * this method will destroy each node's value
					 */
					const int L = it->left ? it->left->val : 0;
					const int R = rightChild ? rightChild->val : 0;
					ans = max(ans, it->val + L + R);
					it->val = max(0, it->val + max(L, R));
				}
				reverseRightSpine(pred);
			}
			root = root->right;
		}
		return ans;
	}
};
