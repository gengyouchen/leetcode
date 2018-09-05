class Solution {
private:
	typedef vector<int>::iterator I;
	typedef unordered_map<int, I> H;
	typedef function<TreeNode*(I, I, I, I)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return NULL;

		H val2inIter;
		for (auto it = inorder.begin(); it != inorder.end(); ++it)
			val2inIter[*it] = it;

		F dfs = [&](auto preFirst, auto preLast, auto inFirst, auto inLast) {
			auto curr = new TreeNode(*preFirst);
			if (distance(preFirst, preLast) > 1) {
				++preFirst;
				int L = distance(inFirst, val2inIter[curr->val]);
				int R = distance(inFirst, inLast) - L - 1;

				if (L > 0)
					curr->left = dfs(preFirst, preFirst + L, inFirst, inFirst + L);
				if (R > 0)
					curr->right = dfs(preLast - R, preLast, inLast - R, inLast);
			}
			return curr;
		};

		return dfs(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};
