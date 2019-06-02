class Solution {
public:
	/* time: O(n), space: O(n) */
	static vector<vector<int>> verticalOrder(const TreeNode* root) {
		if (!root)
			return {};
		list<vector<int>> slots;
		queue<pair<const TreeNode*, list<vector<int>>::iterator>> Q;
		slots.emplace_back(), Q.emplace(root, slots.begin());
		while (!Q.empty()) {
			auto it = Q.front().second;
			root = Q.front().first, Q.pop(), it->push_back(root->val);
			if (root->left) {
				auto L = it;
				if (it == slots.begin())
					slots.emplace_front();
				Q.emplace(root->left, --L);
			}
			if (root->right) {
				auto R = it;
				if (++it == slots.end())
					slots.emplace_back();
				Q.emplace(root->right, ++R);
			}
		}
		vector<vector<int>> ans;
		for (auto& slot : slots)
			ans.emplace_back(move(slot));
		return ans;
	}
};
