class Solution {
private:
	typedef function<TreeNode*(TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		if (inorder.empty())
			return NULL;
		auto inIter = inorder.rbegin(), postIter = postorder.rbegin();
		/*
		 * Propagate the predecessor link to mimic the threaded binary tree
		 * in order to know when should we stop constructing the sub-tree
		 */
		F dfs = [&](auto pred) {
			auto curr = new TreeNode(*postIter++);

			if (*inIter != curr->val)
				curr->right = dfs(curr);

			assert(*inIter == curr->val);
			++inIter;

			if (pred ? (*inIter != pred->val) : (inIter != inorder.rend()))
				curr->left = dfs(pred);

			return curr;
		};
		return dfs(NULL);
	}
};
