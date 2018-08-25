class Solution {
private:
	template <class I>
	TreeNode* construct(I preorderFirst, I preorderLast, I inorderFirst, I inorderLast) {
		if (preorderFirst == preorderLast)
			return NULL;

		I inorderRoot = find(inorderFirst, inorderLast, *preorderFirst);
		int L = distance(inorderFirst, inorderRoot);
		int R = distance(inorderRoot + 1, inorderLast);

		TreeNode *root = new TreeNode(*preorderFirst++);
		root->left = construct(preorderFirst, preorderFirst + L, inorderFirst, inorderFirst + L);
		root->right = construct(preorderLast - R, preorderLast, inorderLast - R, inorderLast);
		return root;
	}
public:
	/* time: O(n^2), space: O(n) */
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return construct(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};
