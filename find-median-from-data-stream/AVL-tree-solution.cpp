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
	K select(int rank) const {
		assert(rank <= size(root));
		auto p = root;
		while (rank != size(p->left) + 1) {
			if (rank <= size(p->left))
				p = p->left;
			else
				rank -= size(p->left) + 1, p = p->right;
		}
		return p->key;
	}
	~OrderStatisticTree() { erase(root); }
	int size() const { return size(root); }
};

class MedianFinder {
private:
	OrderStatisticTree<int> ost;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count tree itself) */
	MedianFinder() {}

	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count tree itself) */
	void addNum(int num) {
		ost.insert(num);
	}

	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count tree itself) */
	double findMedian() const {
		const int n = ost.size();
		if (n % 2)
			return ost.select((n + 1) / 2);
		return ((double)ost.select(n / 2) + (double)ost.select(n / 2 + 1)) / 2;
	}
};
