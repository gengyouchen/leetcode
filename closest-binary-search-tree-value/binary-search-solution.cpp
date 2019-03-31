class Solution {
public:
	/* time: O(n), space: O(1) */
	int closestValue(const TreeNode* root, double target) {
		int ans;
		double bestDiff = DBL_MAX;
		while (root) {
			const double diff = abs(root->val - target);
			if (diff < bestDiff)
				bestDiff = diff, ans = root->val;
			if (target < root->val)
				root = root->left;
			else if (target > root->val)
				root = root->right;
			else
				root = NULL;
		}
		return ans;
	}
};
