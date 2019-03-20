class Solution {
public:
	/* time: O(n), space: O(n) */
	TreeNode* bstFromPreorder(const vector<int>& preorder) {
		/*
		 * See LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal
		 * The method is the same. BST implicitly gives us its in-order sequence.
		 */
		stack<TreeNode*> successors;
		TreeNode *leftParent = NULL, *ans = NULL;
		auto it = preorder.begin();
		while (it != preorder.end()) {
			if (!successors.empty() && successors.top()->val < *it) {
				leftParent = successors.top(), successors.pop();
			} else {
				auto curr = new TreeNode(*it++);
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
