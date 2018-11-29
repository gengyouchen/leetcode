class Solution {
public:
	/* time: O(n), space: O(n) */
	bool isBalanced(const TreeNode* root) {
		bool ans = true;
		unordered_map<const TreeNode*, int> height;
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
				const int L = height[root->left], R = height[root->right];
				ans = ans && (R - L <= 1) && (R - L >= -1);
				height[root] = 1 + max(L, R);
				prev = root, root = NULL;
			}
		return ans;
	}
};
