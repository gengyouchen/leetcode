class Solution {
private:
	typedef const TreeNode* T;
	typedef pair<T, int> P;
	typedef vector<P> S;
public:
	/* time: O(n^2), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> pathSum(const TreeNode* root, int sum) {
		if (!root)
			return {};
		vector<vector<int>> ans;
		int depth = root->val;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		S succ; /* store successors to mimic threaded binary trees */
		const TreeNode* prev = NULL;
		while (root || !succ.empty())
			if (root)
				succ.emplace_back(root, depth), root = root->left, depth += (root ? root->val : 0);
			else {
				root = succ.back().first, depth = succ.back().second;
				if (root->right && root->right != prev) {
					root = root->right, depth += (root ? root->val : 0);
					continue;
				}
				if (isLeaf(root) && depth == sum) {
					ans.emplace_back();
					for (auto it : succ)
						ans.back().push_back(it.first->val);
				}
				succ.pop_back();
				prev = root, root = NULL;
			}
		return ans;
	}
};
