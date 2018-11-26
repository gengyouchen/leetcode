class Solution {
private:
	typedef function<TreeNode*(TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		if (preorder.empty())
			return NULL;
		auto preIter = preorder.begin(), inIter = inorder.begin();
		/*
		 * Propagate the successor link to mimic the threaded binary tree
		 * in order to know when should we stop constructing the sub-tree
		 */
		F dfs = [&](auto succ) {
			auto curr = new TreeNode(*preIter++);

			if (*inIter != curr->val)
				curr->left = dfs(curr);

			assert(*inIter == curr->val);
			++inIter;

			if (succ ? (*inIter != succ->val) : (inIter != inorder.end()))
				curr->right = dfs(succ);

			return curr;
		};
		return dfs(NULL);
	}
};
