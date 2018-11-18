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
		stack<T> succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.push(root), root = L(root);
			else {
				root = succ.top(), succ.pop();
				root = R(root);
			}
		return ans;
	}
public:
	/* time: O(n), space: O(n) */
	TreeNode* sortedListToBST(const ListNode* head) {
		if (!head)
			return NULL;
		T root = allocCompleteBST(countList(head)), ans = root;
		stack<T> succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.push(root), root = root->left;
			else {
				root = succ.top(), succ.pop();
				root->val = head->val;
				head = head->next, root = root->right;
			}
		return ans;
	}
};
