class Solution {
private:
	typedef TreeNode* T;
	typedef function<void(T, int)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) {
		TreeNode *ans = NULL;
		int minDepth = INT_MAX, nFound = 0;
		F dfs = [&](auto curr, int depth) {
			if (curr) {
				dfs(curr->left, depth + 1);
				if (nFound < 2) {
					if (curr == p || curr == q) {
						if (!ans)
							ans = curr, minDepth = depth;
						++nFound;
					}
					if (ans && depth < minDepth)
						ans = curr, minDepth = depth;
				}
				dfs(curr->right, depth + 1);
			}
		};
		dfs(root, 1);
		return ans;
	}
};
