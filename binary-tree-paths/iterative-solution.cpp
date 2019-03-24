class Solution {
public:
	/* time: O(n^2), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<string> binaryTreePaths(const TreeNode* root) {
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		vector<string> ans;
		vector<const TreeNode*> parents;
		const TreeNode* prev = NULL;
		while (root || !parents.empty()) {
			if (root) {
				parents.push_back(root), root = root->left;
			} else {
				root = parents.back();
				if (root->right && root->right != prev) {
					root = root->right;
					continue;
				}
				if (isLeaf(root)) {
					ans.emplace_back();
					for (auto p : parents) {
						if (!ans.back().empty())
							ans.back() += "->";
						ans.back() += to_string(p->val);
					}
				}
				prev = root;
				parents.pop_back(), root = NULL;
			}
		}
		return ans;
	}
};
