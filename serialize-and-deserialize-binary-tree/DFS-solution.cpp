class Codec {
public:
	/* time: O(n), space: O(n) */
	static string serialize(const TreeNode* root) {
		ostringstream oss;
		stack<const TreeNode*> S;
		S.push(root);
		while (!S.empty()) {
			root = S.top(), S.pop();
			if (root)
				oss << root->val << '/', S.push(root->right), S.push(root->left);
			else
				oss << "#/";
		}
		return oss.str();
	}
	/* time: O(n), space: O(n) */
	static TreeNode* deserialize(const string& data) {
		istringstream iss(data);
		string key;
		getline(iss, key, '/');
		if (key == "#")
			return NULL;

		auto root = new TreeNode(stoi(key)), p = root;
		stack<pair<TreeNode*, bool>> S;
		S.emplace(p, true), S.emplace(p, false);
		while (!S.empty()) {
			const bool isRightSide = S.top().second;
			p = S.top().first, S.pop(), getline(iss, key, '/');
			if (key != "#") {
				const auto child = new TreeNode(stoi(key));
				if (isRightSide)
					p->right = child;
				else
					p->left = child;
				S.emplace(child, true), S.emplace(child, false);
			}
		}
		return root;
	}
};
