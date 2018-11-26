class Solution {
private:
	typedef TreeNode* T;
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	TreeNode* sortedArrayToBST(const vector<int>& nums) {
		if (nums.empty())
			return NULL;

		/* Imagine that we have a complete binary tree with n nodes */
		const int n = nums.size();
		auto L = [&](T p, int i) -> T& { if (!p->left && i * 2 <= n) p->left = new TreeNode(0); return p->left; };
		auto R = [&](T p, int i) -> T& { if (!p->right && i * 2 + 1 <= n) p->right = new TreeNode(0); return p->right; };

		T root = new TreeNode(0), ans = root;
		int i = 1, depth = 1;
		auto it = nums.begin();
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 *     LeetCode 104 - Maximum Depth of Binary Tree
		 *     LeetCode 111 - Minimum Depth of Binary Tree
		 */
		while (root) {
			if (L(root, i)) {
				auto pred = L(root, i);
				int j = i * 2, deltaDepth = 1; /* between root and pred */
				while (R(pred, j) && R(pred, j) != root)
					pred = R(pred, j), j = j * 2 + 1, ++deltaDepth;
				if (!R(pred, j)) {
					R(pred, j) = root;
					root = L(root, i), i = i * 2, ++depth;
					continue;
				}
				R(pred, j) = NULL;
				i /= 2, --depth; /* rollback to pred's depth */
				i >>= deltaDepth, depth -= deltaDepth;
			}
			root->val = *it++;
			root = R(root, i), i = i * 2 + 1, ++depth;
		}
		return ans;
	}
};
