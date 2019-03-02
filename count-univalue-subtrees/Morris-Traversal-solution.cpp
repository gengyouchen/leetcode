class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	int countUnivalSubtrees(TreeNode* root) {
		int ans = 0;
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
					 * However, we modify node i's value field
					 * to represent its return value is FALSE
					 *
					 * Warning:
					 * this method will destroy each node's value
					 */
					const auto parent = it->right ? it->right : root;
					const bool L = !it->left || it->left->val == it->val;
					const bool R = !rightChild || rightChild->val == it->val;
					const bool ret = L && R;
					if (ret)
						++ans;
					else if (parent->val == it->val)
						it->val = ~it->val;
				}
				reverseRightSpine(pred);
			}
			root = root->right;
		}
		return ans;
	}
};
