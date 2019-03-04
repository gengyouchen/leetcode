class Solution {
private:
	typedef TreeNode* T;
	typedef pair<T, int> P;
	typedef stack<P> S;
public:
	/* time: O(n), space: O(n) */
	TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) {
		if (!root)
			return 0;
		TreeNode *ans = NULL;
		int depth = 1, minDepth = INT_MAX, nFound = 0;
		S succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty()) {
			if (root)
				succ.emplace(root, depth), root = root->left, ++depth;
			else {
				root = succ.top().first, depth = succ.top().second, succ.pop();
				if (nFound < 2) {
					if (root == p || root == q) {
						if (!ans)
							ans = root, minDepth = depth;
						++nFound;
					}
					if (ans && depth < minDepth)
						ans = root, minDepth = depth;
				}
				root = root->right, ++depth;
			}
		}
		return ans;
	}
};
