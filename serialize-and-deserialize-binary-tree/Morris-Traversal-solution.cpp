class Codec {
private:
	template <class I>
	static pair<bool, int> readNextKey(I& it) {
		bool valid = true, negative = false;
		int num = 0;
		for (char c = *it++; c != '/'; c = *it++) {
			if (c == '#')
				valid = false;
			else if (c == '-')
				negative = true;
			else
				num = num * 10 + (c - '0');
		}
		return {valid, negative ? -num : num};
	};
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static string serialize(TreeNode* root) {
		string ans;
		while (root) {
			if (root->left) {
				auto pred = root->left;
				while (pred->right && pred->right != root)
					pred = pred->right;
				if (!pred->right) {
					pred->right = root, ans += to_string(root->val) + '/', root = root->left;
					continue;
				}
				pred->right = NULL, ans += "#/";
			} else {
				ans += to_string(root->val) + "/#/";
			}
			root = root->right;
		}
		ans += "#/";
		return ans;
	}
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static TreeNode* deserialize(const string& data) {
		auto it = data.begin();
		auto key = readNextKey(it);
		if (!key.first)
			return NULL;

		auto root = new TreeNode(key.second), p = root;
		bool leftVisited = false;
		while (p && it != data.end()) {
			const auto succ = p->right;
			key = readNextKey(it);
			if (key.first) {
				const auto child = new TreeNode(key.second);
				if (leftVisited)
					p->right = child, child->right = succ, p = child, leftVisited = false;
				else
					p->left = child, child->right = p, p = child;
			} else {
				if (leftVisited)
					p->right = NULL, p = succ;
				else
					leftVisited = true;
			}
		}
		return root;
	}
};
