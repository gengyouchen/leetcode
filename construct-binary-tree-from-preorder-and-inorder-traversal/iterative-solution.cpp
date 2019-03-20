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
		stack<TreeNode*> successors;
		TreeNode *leftParent = NULL, *ans = NULL;
		auto discovery = preorder.begin(), finishing = inorder.begin();
		while (finishing != inorder.end()) {
			if (!successors.empty() && successors.top()->val == *finishing) {
				++finishing, leftParent = successors.top(), successors.pop();
			} else {
				auto curr = new TreeNode(*discovery++);
				if (leftParent)
					leftParent->right = curr;
				else if (!successors.empty())
					successors.top()->left = curr;
				else
					ans = curr;

				/* move insertion position to curr->left */
				successors.push(curr), leftParent = NULL;
			}
		}
		return ans;
	}
};
