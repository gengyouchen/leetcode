class Solution {
private:
	typedef tuple<const TreeNode*, int, int> T;
	typedef stack<T> S;
public:
	/* time: O(n), space: O(n) */
	bool isBalanced(const TreeNode* root) {
		bool ans = true;
		S parents;
		const TreeNode* prev = NULL;
		int prevRet = 0;
		while (root || !parents.empty()) {
			if (root)
				parents.push({root, 0, 0}), root = root->left;
			else {
				root = get<0>(parents.top());
				int &L = get<1>(parents.top()), &R = get<2>(parents.top());

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

				ans = ans && (R - L <= 1) && (R - L >= -1);
				prev = root, prevRet = 1 + max(L, R);
				parents.pop(), root = NULL;
			}
		}
		return ans;
	}
};
