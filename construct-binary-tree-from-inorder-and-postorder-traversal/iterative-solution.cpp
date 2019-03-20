class Solution {
public:
	/* time: O(n), space: O(n) */
	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		/*
		 * See LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal
		 * The method is the same. We just scan from right to left.
		 */
		stack<TreeNode*> predecessors;
		TreeNode *rightParent = NULL, *ans = NULL;
		auto discovery = postorder.rbegin(), finishing = inorder.rbegin();
		while (finishing != inorder.rend()) {
			if (!predecessors.empty() && predecessors.top()->val == *finishing) {
				++finishing, rightParent = predecessors.top(), predecessors.pop();
			} else {
				auto curr = new TreeNode(*discovery++);
				if (rightParent)
					rightParent->left = curr;
				else if (!predecessors.empty())
					predecessors.top()->right = curr;
				else
					ans = curr;

				/* move insertion position to curr->right */
				predecessors.push(curr), rightParent = NULL;
			}
		}
		return ans;
	}
};
