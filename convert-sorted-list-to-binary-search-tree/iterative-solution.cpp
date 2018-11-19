class Solution {
private:
	typedef TreeNode* T;
	typedef pair<T, int> P;
	typedef stack<P> S;
	int countList(const ListNode* head) {
		int len = 0;
		while (head)
			head = head->next, ++len;
		return len;
	}
public:
	/* time: O(n), space: O(n) */
	TreeNode* sortedListToBST(const ListNode* head) {
		if (!head)
			return NULL;

		/* Imagine that we have a complete binary tree with n nodes */
		const int n = countList(head);
		auto L = [&](T p, int i) { if (!p->left && i * 2 <= n) p->left = new TreeNode(0); return p->left; };
		auto R = [&](T p, int i) { if (!p->right && i * 2 + 1 <= n) p->right = new TreeNode(0); return p->right; };

		T root = new TreeNode(0), ans = root;
		int i = 1;
		S succ; /* store successors to mimic threaded binary trees */
		while (root || !succ.empty())
			if (root)
				succ.emplace(root, i), root = L(root, i), i = i * 2;
			else {
				root = succ.top().first, i = succ.top().second, succ.pop();
				root->val = head->val, head = head->next;
				root = R(root, i), i = i * 2 + 1;
			}
		return ans;
	}
};
