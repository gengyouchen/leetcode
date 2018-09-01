class Solution {
private:
	typedef vector<int>::iterator I;
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return NULL;

		unordered_map<int, I> val2inIter;
		for (auto it = inorder.begin(); it != inorder.end(); ++it)
			val2inIter[*it] = it;

		function<TreeNode*(I, I, I, I)> dfs = [&](I preFirst, I preLast, I inFirst, I inLast) {
			auto curr = new TreeNode(*preFirst++);
			int lSize = distance(inFirst, val2inIter[curr->val]);
			int rSize = distance(val2inIter[curr->val] + 1, inLast);

			if (lSize > 0)
				curr->left = dfs(preFirst, preFirst + lSize, inFirst, inFirst + lSize);
			if (rSize > 0)
				curr->right = dfs(preLast - rSize, preLast, inLast - rSize, inLast);
			return curr;
		};

		return dfs(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};
