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
	double mid;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count tree itself) */
	MedianFinder() {
		srand(time(NULL));
	}

	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count tree itself) */
	void addNum(int num) {
		ost.insert(num);
		const int n = ost.size();
		if (n % 2)
			mid = ost.select((n + 1) / 2);
		else
			mid = ((double)ost.select(n / 2) + (double)ost.select(n / 2 + 1)) / 2;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count tree itself) */
	double findMedian() const {
		return mid;
	}
};
