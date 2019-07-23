class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* constructFromPrePost(const vector<int>& pre, const vector<int>& post) {
		const int n = pre.size();
		TreeNode *ans = NULL;
		stack<TreeNode*> parent;

		for (int i = 0, j = 0; i < n; ++i) {
			auto curr = new TreeNode(pre[i]);
			if (!ans)
				ans = curr;

			while (!parent.empty() && post[j] == parent.top()->val)
				parent.pop(), ++j;

			if (!parent.empty()) {
				if (parent.top()->left)
					parent.top()->right = curr;
				else
					parent.top()->left = curr;
			}
			parent.push(curr);
		}
		return ans;
	}
};
