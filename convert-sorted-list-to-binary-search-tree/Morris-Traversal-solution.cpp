class Solution {
private:
	typedef TreeNode* T;
	int countList(const ListNode* head) {
		int len = 0;
		while (head)
			head = head->next, ++len;
		return len;
	}
	T allocCompleteBST(int n) {
		T root = new TreeNode(1), ans = root;
		auto L = [&](T x) -> T& {
			const int idx = x->val * 2;
			if (!x->left && idx <= n)
				x->left = new TreeNode(idx);
			return x->left;
		};
		auto R = [&](T x) -> T& {
			const int idx = x->val * 2 + 1;
			if (!x->right && idx <= n)
				x->right = new TreeNode(idx);
			return x->right;
		};
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
		while (root) {
			if (L(root)) {
				auto pred = L(root);
				while (R(pred) && R(pred) != root)
					pred = R(pred);
				if (!R(pred)) {
					R(pred) = root;
					root = L(root);
					continue;
				}
				R(pred) = NULL;
			}
			root = R(root);
		}
		return ans;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	TreeNode* sortedListToBST(const ListNode* head) {
		if (!head)
			return NULL;
		T root = allocCompleteBST(countList(head)), ans = root;
		/*
		 * Use the "Morris Traversal" method to achieve O(1) auxiliary space
		 * See LeetCode 94 - Binary Tree Inorder Traversal
		 */
		while (root) {
			if (root->left) {
				auto pred = root->left;
				while (pred->right && pred->right != root)
					pred = pred->right;
				if (!pred->right) {
					pred->right = root;
					root = root->left;
					continue;
				}
				pred->right = NULL;
			}
			root->val = head->val;
			head = head->next, root = root->right;
		}
		return ans;
	}
};
