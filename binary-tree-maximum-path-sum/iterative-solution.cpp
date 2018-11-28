class Solution {
public:
	/* time: O(n), space: O(n) */
	int maxPathSum(const TreeNode* root) {
		int ans = INT_MIN;
		unordered_map<const TreeNode*, int> maxToRoot;
		stack<const TreeNode*> succ; /* store successors to mimic threaded binary trees */
		const TreeNode* prev = NULL;
		while (root || !succ.empty())
			if (root)
				succ.push(root), root = root->left;
			else {
				root = succ.top();
				if (root->right && root->right != prev) {
					root = root->right;
					continue;
				}
				succ.pop();
				const int L = maxToRoot[root->left], R = maxToRoot[root->right];
				ans = max(ans, root->val + L + R);
				maxToRoot[root] = max(0, root->val + max(L, R));
				prev = root, root = NULL;
			}
		return ans;
	}
};
