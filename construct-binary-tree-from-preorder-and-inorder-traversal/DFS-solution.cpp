class Solution {
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return NULL;

		auto preIter = preorder.begin();
		auto inIter = inorder.begin();

		function<TreeNode*(TreeNode*)> dfs = [&](auto inStop) {
			auto curr = new TreeNode(*preIter++);

			if (*inIter != curr->val)
				curr->left = dfs(curr);

			assert(*inIter == curr->val);
			++inIter;

			if (inStop ? (*inIter != inStop->val) : (inIter != inorder.end()))
				curr->right = dfs(inStop);

			return curr;
		};

		return dfs(NULL);
	}
};
