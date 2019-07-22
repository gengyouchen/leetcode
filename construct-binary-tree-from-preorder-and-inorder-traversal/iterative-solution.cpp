class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		const int n = preorder.size();
		TreeNode *ans = NULL;
		stack<TreeNode*> succ;

		for (int i = 0, j = 0; i < n; ++i) {
			TreeNode *curr = new TreeNode(preorder[i]);
			if (!ans)
				ans = curr;

			TreeNode *p = NULL;
			while (!succ.empty() && inorder[j] == succ.top()->val)
				p = succ.top(), succ.pop(), ++j;

			if (p)
				p->right = curr;
			else if (!succ.empty())
				succ.top()->left = curr;
			succ.push(curr);
		}
		return ans;
	}
};
