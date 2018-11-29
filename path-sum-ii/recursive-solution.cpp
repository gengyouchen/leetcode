class Solution {
private:
	typedef const TreeNode* T;
	typedef function<void(T, int)> F;
public:
	/* time: O(n^2), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> pathSum(const TreeNode* root, int sum) {
		if (!root)
			return {};
		vector<vector<int>> ans;
		vector<int> buf;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		F dfs = [&](auto p, int depth) {
			if (p) {
				buf.push_back(p->val), depth += p->val;
				dfs(p->left, depth);
				dfs(p->right, depth);
				if (isLeaf(p) && depth == sum)
					ans.push_back(buf);
				buf.pop_back();
			}
		};
		dfs(root, 0);
		return ans;
	}
};
