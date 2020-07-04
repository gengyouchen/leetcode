class Solution {
public:
	/* time: O(n), space: O(n) */
	static TreeNode* bstFromPreorder(const vector<int>& preorder) {
		TreeNode *ans = NULL;
		stack<TreeNode*> succ;
		for (int val : preorder) {
			TreeNode *curr = new TreeNode(val);
			if (!ans)
				ans = curr;

			TreeNode *p = NULL;
			while (!succ.empty() && val > succ.top()->val)
				p = succ.top(), succ.pop();

			if (p)
				p->right = curr;
			else if (!succ.empty())
				succ.top()->left = curr;
			succ.push(curr);
		}
		return ans;
	}
};
