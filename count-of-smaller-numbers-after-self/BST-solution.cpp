class OrderStatisticTree {
private:
	struct TreeNode {
		int key, h = 1, size = 1;
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
	void insert(int key) {
		auto x = new TreeNode();
		x->key = key, root = insert(root, x);
	}
	int rank(int key) const {
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
public:
	/* time: O(n*log(n)), space: O(n) */
	static vector<int> countSmaller(const vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n);
		OrderStatisticTree ost;
		for (int i = n - 1; i >= 0; --i)
			ans[i] = ost.rank(nums[i]), ost.insert(nums[i]);
		return ans;
	}
};
