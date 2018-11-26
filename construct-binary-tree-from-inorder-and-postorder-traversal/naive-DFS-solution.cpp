class Solution {
private:
	typedef vector<int>::const_iterator I;
	typedef unordered_map<int, I> H;
	typedef function<TreeNode*(I, I, I, I)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		if (inorder.empty())
			return NULL;

		H val2inIter;
		for (auto it = inorder.begin(); it != inorder.end(); ++it)
			val2inIter[*it] = it;

		F dfs = [&](auto inFirst, auto inLast, auto postFirst, auto postLast) {
			auto curr = new TreeNode(*(postLast - 1));
			if (distance(postFirst, postLast) > 1) {
				--postLast;
				const int L = distance(inFirst, val2inIter[curr->val]);
				const int R = distance(inFirst, inLast) - L - 1;

				if (L > 0)
					curr->left = dfs(inFirst, inFirst + L, postFirst, postFirst + L);
				if (R > 0)
					curr->right = dfs(inLast - R, inLast, postLast - R, postLast);
			}
			return curr;
		};
		return dfs(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};
