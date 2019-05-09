class Codec {
public:
	/* time: O(n), space: O(n) */
	static string serialize(const TreeNode* root) {
		ostringstream oss;
		queue<const TreeNode*> Q;
		Q.push(root);
		while (!Q.empty()) {
			root = Q.front(), Q.pop();
			if (root)
				oss << root->val << '/', Q.push(root->left), Q.push(root->right);
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
		queue<pair<TreeNode*, bool>> Q;
		Q.emplace(p, false), Q.emplace(p, true);
		while (!Q.empty()) {
			const bool isRightSide = Q.front().second;
			p = Q.front().first, Q.pop(), getline(iss, key, '/');
			if (key != "#") {
				const auto child = new TreeNode(stoi(key));
				if (isRightSide)
					p->right = child;
				else
					p->left = child;
				Q.emplace(child, false), Q.emplace(child, true);
			}
		}
		return root;
	}
};
