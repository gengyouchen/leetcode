class Solution {
private:
	int countList(ListNode* head) {
		int len = 0;
		while (head)
			head = head->next, ++len;
		return len;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		auto out = &dummy;
		while (l1 && l2)
			if (l1->val < l2->val)
				out->next = l1, out = out->next, l1 = l1->next;
			else
				out->next = l2, out = out->next, l2 = l2->next;
		if (l1)
			out->next = l1;
		if (l2)
			out->next = l2;
		return dummy.next;
	}
public:
	/* time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input & output itself) */
	ListNode* sortList(ListNode* head) {
		const int n = countList(head);
		for (int step = 1; step < n; step *= 2) {
			ListNode dummy(0);
			auto out = &dummy;

			while (head) {
				ListNode pre1(0), pre2(0);
				auto l1 = &pre1, l2 = &pre2;

				for (int i = 0; i < step && head; ++i)
					l1->next = head, l1 = l1->next, head = head->next;
				l1->next = NULL;

				for (int i = 0; i < step && head; ++i)
					l2->next = head, l2 = l2->next, head = head->next;
				l2->next = NULL;

				out->next = mergeTwoLists(pre1.next, pre2.next);
				while (out->next)
					out = out->next;
			}
			head = dummy.next;
		}
		return head;
	}
};
