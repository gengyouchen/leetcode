class Solution {
private:
	stack<const TreeNode*> pred, succ;
	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count predecessor stack itself) */
	const TreeNode* getPredecessor() {
		const TreeNode *ret = NULL;
		if (!pred.empty()) {
			ret = pred.top(), pred.pop();
			auto p = ret;
			if (p = p->left) {
				while (p)
					pred.push(p), p = p->right;
			}
		}
		return ret;
	}
	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count successor stack itself) */
	const TreeNode* getSuccessor() {
		const TreeNode *ret = NULL;
		if (!succ.empty()) {
			ret = succ.top(), succ.pop();
			auto p = ret;
			if (p = p->right) {
				while (p)
					succ.push(p), p = p->left;
			}
		}
		return ret;
	}
public:
	/*
	 * time: O(h + k), space: O(h) auxiliary (i.e. does not count output itself),
	 * where h = log(n) if BST is balanced
	 */
	vector<int> closestKValues(const TreeNode* root, double target, int k) {
		if (k <= 0)
			return {};

		while (root) {
			if (target < root->val)
				succ.push(root), root = root->left;
			else
				pred.push(root), root = root->right;
		}

		vector<int> ans;
		auto prev = getPredecessor(), next = getSuccessor();
		while (ans.size() < k) {
			if (!prev || (next && abs(target - prev->val) > abs(target - next->val)))
				ans.push_back(next->val), next = getSuccessor();
			else
				ans.push_back(prev->val), prev = getPredecessor();
		}
		return ans;
	}
};
