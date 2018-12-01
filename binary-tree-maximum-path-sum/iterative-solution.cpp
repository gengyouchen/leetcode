class Solution {
private:
	typedef tuple<const TreeNode*, int, int> T;
	typedef stack<T> S;
public:
	/* time: O(n), space: O(n) */
	int maxPathSum(const TreeNode* root) {
		int ans = INT_MIN;
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

				ans = max(ans, root->val + L + R);
				prev = root, prevRet = max(0, root->val + max(L, R));;
				parents.pop(), root = NULL;
			}
		}
		return ans;
	}
};
