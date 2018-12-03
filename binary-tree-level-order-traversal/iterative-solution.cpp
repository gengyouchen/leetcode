class Solution {
public:
	/* time: O(n), space: O(n) */
	vector<vector<int>> levelOrder(const TreeNode* root) {
		if (!root)
			return {};
		vector<vector<int>> ans;
		deque<const TreeNode*> in, out;
		in.push_back({root});
		while (!in.empty()) {
			ans.emplace_back();
			for (auto p : in) {
				ans.back().push_back(p->val);
				if (p->left)
					out.push_back(p->left);
				if (p->right)
					out.push_back(p->right);
			}
			in = move(out);
		}
		return ans;
	}
};
