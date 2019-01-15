class Solution {
private:
	typedef pair<int, int> PII;
	typedef tuple<const TreeNode*, PII, PII> T;
	typedef stack<T> S;
public:
	/* time: O(n), space: O(n) */
	int rob(const TreeNode* root) {
		int ans = 0;
		S parents;
		const TreeNode* prev = NULL;
		PII prevRet;
		while (root || !parents.empty()) {
			if (root)
				parents.push({root, PII(), PII()}), root = root->left;
			else {
				root = get<0>(parents.top());
				PII &L = get<1>(parents.top()), &R = get<2>(parents.top());

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

				const int rootTaken = root->val + L.second + R.second;
				const int rootSkipped = max(L.first, L.second) + max(R.first, R.second);
				ans = max(ans, max(rootTaken, rootSkipped));
				prev = root, prevRet = PII(rootTaken, rootSkipped);
				parents.pop(), root = NULL;
			}
		}
		return ans;
	}
};
