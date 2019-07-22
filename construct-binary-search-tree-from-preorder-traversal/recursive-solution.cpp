class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* bstFromPreorder(const vector<int>& preorder) {
		const int n = preorder.size();
		int step = 0;

		using F = function<TreeNode*(const TreeNode*)>;
		F construct = [&](const TreeNode *succ) -> TreeNode* {
			if (step == n || succ && preorder[step] > succ->val)
				return NULL;

			TreeNode *curr = new TreeNode(preorder[step++]);
			curr->left = construct(curr), curr->right = construct(succ);
			return curr;
		};

		return construct(NULL);
	}
};
