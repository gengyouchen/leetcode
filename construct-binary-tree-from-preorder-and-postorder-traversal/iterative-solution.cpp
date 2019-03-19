class Solution {
public:
	/* time: O(n), space: O(n) */
	TreeNode* constructFromPrePost(const vector<int>& pre, const vector<int>& post) {
		stack<TreeNode*> parents;
		TreeNode *curr = NULL, *ans = NULL;
		auto discovery = pre.begin(), finishing = post.begin();
		while (finishing != post.end()) {
			if (curr && curr->val == *finishing) {
				++finishing, curr = parents.top(), parents.pop();
			} else {
				auto child = new TreeNode(*discovery++);
				if (!curr)
					ans = child;
				else if (!curr->left)
					curr->left = child;
				else
					curr->right = child;
				parents.push(curr), curr = child;
			}
		}
		return ans;
	}
};
