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
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void reorderList(ListNode* head) {
		if (!head || !head->next)
			return;
		const int n = countList(head);

		auto l1Tail = head;
		for (int i = 0; i < n / 2; ++i)
			l1Tail = l1Tail->next;
		auto l2 = reverseList(l1Tail->next);
		l1Tail->next = NULL;

		auto l1 = head->next;
		while (l1 || l2) {
			if (l2) {
				auto x = l2; /* x = l2.top() */
				l2 = l2->next; /* l2.pop() */
				head->next = x, head = head->next;
			}
			if (l1) {
				auto x = l1; /* x = l1.top() */
				l1 = l1->next; /* l1.pop() */
				head->next = x, head = head->next;
			}
		}
	}
};
