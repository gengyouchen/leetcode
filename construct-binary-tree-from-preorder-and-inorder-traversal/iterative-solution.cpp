class Solution {
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		/*
		 * Example 1:
		 * preorder = [a, b, c, d, e, f, g]
		 * inorder = [a, b, c, d, e, f, g]
		 * answer = a-b-c-d-e-f-g
		 *
		 * Example 2:
		 * preorder = [a, b, c, d, e, f, g]
		 * inorder = [b, c, d, a, e, f, g]
		 * answer = a-e-f-g
		 *          |
		 *          b-c-d
		 */
		auto preIter = preorder.begin(), inIter = inorder.begin();
		stack<TreeNode*> s;
		TreeNode *tail = NULL, *ans = NULL;
		while (preIter != preorder.end()) {
			if (!s.empty() && *inIter == s.top()->val) {
				++inIter, tail = s.top(), s.pop();
			} else {
				if (tail)
					tail = tail->right = new TreeNode(*preIter++);
				else if (s.empty())
					tail = ans = new TreeNode(*preIter++);
				else
					tail = s.top()->left = new TreeNode(*preIter++);

				if (*inIter == tail->val)
					++inIter;
				else
					s.push(tail), tail = NULL;
			}
		}
		return ans;
	}
};
