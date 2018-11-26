class Solution {
private:
	typedef vector<int>::const_reverse_iterator I;
	typedef unordered_map<int, I> H;
	typedef function<TreeNode*(I, I, I, I)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		if (inorder.empty())
			return NULL;

		H val2inIter;
		for (auto it = inorder.rbegin(); it != inorder.rend(); ++it)
			val2inIter[*it] = it;

		F dfs = [&](auto inFirst, auto inLast, auto postFirst, auto postLast) {
			auto curr = new TreeNode(*postFirst);
			if (distance(postFirst, postLast) > 1) {
				++postFirst;
				const int R = distance(inFirst, val2inIter[curr->val]);
				const int L = distance(inFirst, inLast) - R - 1;

				if (R > 0)
					curr->right = dfs(inFirst, inFirst + R, postFirst, postFirst + R);
				if (L > 0)
					curr->left = dfs(inLast - L, inLast, postLast - L, postLast);
			}
			return curr;
		};
		return dfs(inorder.rbegin(), inorder.rend(), postorder.rbegin(), postorder.rend());
	}
};
