class Solution {
private:
	struct Result {
		int size = 0, min = INT_MAX, max = INT_MIN;
	};
public:
	/* time: O(n), space: O(n) */
	int largestBSTSubtree(const TreeNode* root) {
		int ans = 0;
		using F = function<Result(const TreeNode*)>;
		F dfs = [&](auto p) {
			Result ret;
			if (p) {
				const auto L = dfs(p->left), R = dfs(p->right);
				const bool validL = (L.size == 0) || (L.size > 0 && L.max < p->val);
				const bool validR = (R.size == 0) || (R.size > 0 && R.min > p->val);

				if (validL && validR)
					ret.size = 1 + L.size + R.size, ret.min = min(p->val, L.min), ret.max = max(p->val, R.max);
				else
					ret.size = -1;

				ans = max(ans, ret.size);
			}
			return ret;
		};
		dfs(root);
		return ans;
	}
};
