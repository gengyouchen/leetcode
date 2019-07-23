class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		const int n = postorder.size();
		TreeNode *ans = NULL;
		stack<TreeNode*> pred;

		for (int i = n - 1, j = n - 1; i >= 0; --i) {
			TreeNode *curr = new TreeNode(postorder[i]);
			if (!ans)
				ans = curr;

			TreeNode *p = NULL;
			while (!pred.empty() && inorder[j] == pred.top()->val)
				p = pred.top(), pred.pop(), --j;

			if (p)
				p->left = curr;
			else if (!pred.empty())
				pred.top()->right = curr;
			pred.push(curr);
		}
		return ans;
	}
};
