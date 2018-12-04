class Solution {
private:
	typedef tuple<TreeNode*, TreeNode*, TreeNode*> T;
	typedef stack<T> S;
public:
	/* time: O(n), space: O(n) */
	void flatten(TreeNode* root) {
		S parents;
		TreeNode *prev = NULL, *prevRet = NULL;
		while (root || !parents.empty()) {
			if (root)
				parents.push({root, NULL, NULL}), root = root->left;
			else {
				root = get<0>(parents.top());
				auto &L = get<1>(parents.top()), &R = get<2>(parents.top());

				/* store child's returned value */
				if (root->left && root->left == prev)
					L = prevRet;
				if (root->right && root->right == prev)
					R = prevRet;

				/* don't parents.pop() if right child is not visited yet */
				if (root->right && root->right != prev) {
					root = root->right;
					continue;
				}

				if (root->left)
					L->right = root->right, root->right = root->left, root->left = NULL;
				prev = root, prevRet = (R ? R : L ? L : root);
				parents.pop(), root = NULL;
			}
		}
	}
};
