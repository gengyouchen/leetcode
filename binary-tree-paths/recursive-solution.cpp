class Solution {
private:
	typedef const TreeNode* T;
	typedef function<void(T)> F;
public:
	/* time: O(n^2), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<string> binaryTreePaths(const TreeNode* root) {
		vector<string> ans;
		vector<int> buf;
		auto isLeaf = [](auto x) { return x && !x->left && !x->right; };
		F dfs = [&](auto p) {
			if (p) {
				buf.push_back(p->val);
				dfs(p->left);
				dfs(p->right);
				if (isLeaf(p)) {
					ans.emplace_back();
					for (auto val : buf) {
						if (!ans.back().empty())
							ans.back() += "->";
						ans.back() += to_string(val);
					}
				}
				buf.pop_back();
			}
		};
		dfs(root);
		return ans;
	}
};
