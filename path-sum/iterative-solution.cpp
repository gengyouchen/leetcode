class Solution {
private:
	typedef const TreeNode* T;
	typedef pair<T, int> P;
	typedef stack<P> S;
public:
	/* time: O(n), space: O(n) */
	bool hasPathSum(const TreeNode* root, int sum) {
		if (!root)
			return 0;
		bool ans = false;
		int depth = root->val;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		S succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.emplace(root, depth), root = root->left, depth += (root ? root->val : 0);
			else {
				root = succ.top().first, depth = succ.top().second, succ.pop();
				if (isLeaf(root))
					ans = ans || (depth == sum);
				root = root->right, depth += (root ? root->val : 0);
			}
		return ans;
	}
};
