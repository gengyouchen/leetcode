class Solution {
private:
	typedef tuple<const TreeNode*, bool, bool> T;
	typedef stack<T> S;
public:
	/* time: O(n), space: O(n) */
	int countUnivalSubtrees(const TreeNode* root) {
		int ans = 0;
		S parents;
		const TreeNode* prev = NULL;
		int prevRet = 0;
		while (root || !parents.empty()) {
			if (root)
				parents.push({root, false, false}), root = root->left;
			else {
				root = get<0>(parents.top());
				bool &L = get<1>(parents.top()), &R = get<2>(parents.top());

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

				const bool ret =
					(!root->left || root->left->val == root->val && L) &&
					(!root->right || root->right->val == root->val && R);
				if (ret)
					++ans;
				prev = root, prevRet = ret;
				parents.pop(), root = NULL;
			}
		}
		return ans;
	}
};
