class Solution {
private:
	int countList(const ListNode* head) {
		int len = 0;
		while (head)
			head = head->next, ++len;
		return len;
	}
	ListNode* reverseList(ListNode* head) {
		ListNode *buf = NULL;
		while (head) {
			auto x = head; /* x = head.top(); */
			head = head->next; /* head.pop(); */
			x->next = buf, buf = x; /* buf.push(x); */
		}
		return buf;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	bool isPalindrome(ListNode* head) {
		const int n = countList(head);
		if (n <= 1)
			return true;
		auto tail = head;
		for (int i = 0; i < (n + 1) / 2 - 1; ++i)
			tail = tail->next;

		bool ans = true;
		const auto head2 = reverseList(tail->next);
		for (auto p = head, q = head2; p && q; p = p->next, q = q->next) {
			if (p->val != q->val)
				ans = false;
		}
		tail->next = reverseList(head2);
		return ans;
	}
};
