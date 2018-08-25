class Solution {
private:
	template <class I>
	TreeNode* construct(I preorderFirst, I preorderLast, I postorderFirst, I postorderLast) {
		if (preorderFirst == preorderLast)
			return NULL;

		TreeNode *root = new TreeNode(*preorderFirst++);
		if (preorderFirst != preorderLast) {
			I postorderSplit = find(postorderFirst, --postorderLast, *preorderFirst) + 1;
			int L = distance(postorderFirst, postorderSplit);
			int R = distance(postorderSplit, postorderLast);

			root->left = construct(preorderFirst, preorderFirst + L, postorderFirst, postorderFirst + L);
			root->right = construct(preorderLast - R, preorderLast, postorderLast - R, postorderLast);
		}
		return root;
	}
public:
	/* time: O(n^2), space: O(n) */
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		return construct(pre.begin(), pre.end(), post.begin(), post.end());
	}
};
