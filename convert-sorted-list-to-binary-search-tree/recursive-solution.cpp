class Solution {
private:
	typedef TreeNode* T;
	typedef function<void(T)> F;
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
		F dfs = [&](auto p) {
			if (p) {
				dfs(L(p));
				dfs(R(p));
			}
		};
		dfs(root);
		return ans;
	}
public:
	/* time: O(n), space: O(n) */
	TreeNode* sortedListToBST(const ListNode* head) {
		if (!head)
			return NULL;
		T root = allocCompleteBST(countList(head)), ans = root;
		F dfs = [&](auto p) {
			if (p) {
				dfs(p->left);
				p->val = head->val, head = head->next;
				dfs(p->right);
			}
		};
		dfs(root);
		return ans;
	}
};
