class Solution {
private:
	typedef pair<int, int> PII;
	typedef function<PII(const TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	int rob(const TreeNode* root) {
		int ans = 0;
		F robTree = [&](const TreeNode* root) {
			if (!root)
				return make_pair(0, 0);
			const auto L = robTree(root->left), R = robTree(root->right);
			const int rootTaken = root->val + L.second + R.second;
			const int rootSkipped = max(L.first, L.second) + max(R.first, R.second);
			ans = max(ans, max(rootTaken, rootSkipped));
			return make_pair(rootTaken, rootSkipped);
		};
		robTree(root);
		return ans;
	}
};
