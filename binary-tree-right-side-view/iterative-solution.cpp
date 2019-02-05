class Solution {
private:
	typedef const TreeNode* T;
	typedef pair<T, int> P;
	typedef stack<P> S;
public:
	/* time: O(n), space: O(n) */
	vector<int> rightSideView(const TreeNode* root) {
		if (!root)
			return {};
		vector<int> ans;
		int depth = 1;
		S succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty()) {
			if (root) {
				succ.emplace(root, depth), root = root->left, ++depth;
			} else {
				root = succ.top().first, depth = succ.top().second, succ.pop();
				while (ans.size() < depth)
					ans.push_back(0);
				ans[depth - 1] = root->val;
				root = root->right, ++depth;
			}
		}
		return ans;
	}
};
