template <class K>
class OrderStatisticTree {
private:
	struct TreeNode {
		K key;
		int h = 1, size = 1;
		TreeNode *left = NULL, *right = NULL;
	};
	static int h(const TreeNode *root) { return root ? root->h : 0; };
	static int bf(const TreeNode *root) { return h(root->right) - h(root->left); }
	static int size(const TreeNode *root) { return root ? root->size : 0; };
	static void update(TreeNode *root) {
		root->h = 1 + max(h(root->left), h(root->right));
		root->size = 1 + size(root->left) + size(root->right);
	}
	static auto rotateLeft(TreeNode *root) {
		const auto y = root->right, z = y->left;
		y->left = root, root->right = z, update(root), update(y);
		return y;
	}
	static auto rotateRight(TreeNode *root) {
		const auto y = root->left, z = y->right;
		y->right = root, root->left = z, update(root), update(y);
		return y;
	}
	static auto balance(TreeNode *root) {
		if (bf(root) < -1) {
			if (bf(root->left) > 0)
				root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
		if (bf(root) > 1) {
			if (bf(root->right) < 0)
				root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
	}
	static auto insert(TreeNode *root, TreeNode *x) {
		if (!root)
			return x;
		if (x->key < root->key)
			root->left = insert(root->left, x), update(root);
		else
			root->right = insert(root->right, x), update(root);
		return balance(root);
	}
	static void erase(const TreeNode *root) {
		if (root) {
			erase(root->left), erase(root->right);
			delete root;
		}
	}
	TreeNode *root = NULL;
public:
	void insert(const K& key) {
		auto x = new TreeNode();
		x->key = key, root = insert(root, x);
	}
	int rank(const K& key) const {
		int ranking = 1;
		auto p = root;
		while (p) {
			if (key <= p->key)
				p = p->left;
			else
				ranking += 1 + size(p->left), p = p->right;
		}
		return ranking;
	}
	~OrderStatisticTree() { erase(root); }
};

class Solution {
private:
	typedef long long K;
public:
	/* time: O(n*log(n)), space: O(n) */
	static int countRangeSum(const vector<int>& nums, int lower, int upper) {
		const int n = nums.size();
		vector<K> S(n + 1);
		for (int i = 1; i <= n; ++i)
			S[i] = S[i - 1] + nums[i - 1];

		int ans = 0;
		OrderStatisticTree<K> ost;
		for (auto s : S)
			ans += ost.rank(s - lower + 1) - ost.rank(s - upper), ost.insert(s);
		return ans;
	}
};