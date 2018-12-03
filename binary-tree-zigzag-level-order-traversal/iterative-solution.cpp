class Solution {
public:
	/* time: O(n), space: O(n) */
	vector<vector<int>> zigzagLevelOrder(const TreeNode* root) {
		if (!root)
			return {};
		vector<vector<int>> ans;
		deque<const TreeNode*> in, out;
		bool reversed = false;
		in.push_back({root});
		while (!in.empty()) {
			ans.emplace_back();
			for (auto p : in) {
				ans.back().push_back(p->val);
				if (!reversed && p->left)
					out.push_front(p->left);
				if (p->right)
					out.push_front(p->right);
				if (reversed && p->left)
					out.push_front(p->left);
			}
			in = move(out), reversed = !reversed;
		}
		return ans;
	}
};
