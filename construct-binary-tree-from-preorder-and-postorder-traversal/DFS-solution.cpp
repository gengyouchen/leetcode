class Solution {
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		if (pre.empty())
			return NULL;

		auto preIter = pre.begin();
		auto postIter = post.begin();

		function<TreeNode*()> dfs = [&]() {
			auto curr = new TreeNode(*preIter++);

			if (*postIter != curr->val)
				curr->left = dfs();

			if (*postIter != curr->val)
				curr->right = dfs();

			assert(*postIter == curr->val);
			++postIter;

			return curr;
		};

		return dfs();
	}
};
