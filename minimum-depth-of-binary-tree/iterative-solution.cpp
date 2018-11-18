class Solution {
private:
	typedef const TreeNode* T;
	typedef pair<T, int> P;
	typedef stack<P> S;
public:
	/* time: O(n), space: O(n) */
	int minDepth(const TreeNode* root) {
		if (!root)
			return 0;
		int ans = INT_MAX, depth = 1;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		S succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.emplace(root, depth), root = root->left, ++depth;
			else {
				root = succ.top().first, depth = succ.top().second, succ.pop();
				if (isLeaf(root))
					ans = min(ans, depth);
				root = root->right, ++depth;
			}
		return ans;
	}
};
