class Solution {
private:
	typedef const TreeNode* T;
	typedef pair<T, int> P;
	typedef stack<P> S;
public:
	/* time: O(n), space: O(n) */
	int sumNumbers(const TreeNode* root) {
		if (!root)
			return 0;
		int ans = 0;
		S discovered;
		discovered.emplace(root, 0);
		while (!discovered.empty()) {
			const auto p = discovered.top().first;
			const int val = discovered.top().second * 10 + p->val;
			discovered.pop();

			if (!p->right && !p->left)
				ans += val;
			if (p->right)
				discovered.emplace(p->right, val);
			if (p->left)
				discovered.emplace(p->left, val);
		}
		return ans;
	}
};
