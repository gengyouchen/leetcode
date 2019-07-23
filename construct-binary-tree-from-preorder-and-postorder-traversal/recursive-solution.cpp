class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* constructFromPrePost(const vector<int>& pre, const vector<int>& post) {
		const int n = pre.size();
		int i = 0, j = 0;

		using F = function<TreeNode*(const TreeNode*)>;
		F construct = [&](auto succ) {
			if (i == n || succ && post[j] == succ->val)
				return (TreeNode *)NULL;

			auto curr = new TreeNode(pre[i++]);
			curr->left = construct(curr), curr->right = construct(curr), ++j;
			return curr;
		};

		return construct(NULL);
	}
};
