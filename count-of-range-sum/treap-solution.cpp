template <class K>
class OrderStatisticTree {
private:
	struct TreeNode {
		K key;
		int priority, size = 1;
		TreeNode *left = NULL, *right = NULL;
	};
	static int size(const TreeNode *root) { return root ? root->size : 0; };
	static void update(TreeNode *root) {
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
	static auto insert(TreeNode *root, TreeNode *x) {
		if (!root)
			return x;
		if (x->key < root->key) {
			root->left = insert(root->left, x), update(root);
			if (root->priority > root->left->priority)
				return rotateRight(root);
		} else {
			root->right = insert(root->right, x), update(root);
			if (root->priority > root->right->priority)
				return rotateLeft(root);
		}
		return root;
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
		x->key = key, x->priority = rand(), root = insert(root, x);
	}
	int countSmaller(const K& key) const {
		int count = 0;
		auto p = root;
		while (p) {
			if (key <= p->key)
				p = p->left;
			else
				count += 1 + size(p->left), p = p->right;
		}
		return count;
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
		for (const auto& s : S)
			ans += ost.countSmaller(s - lower + 1) - ost.countSmaller(s - upper), ost.insert(s);
		return ans;
	}
};
