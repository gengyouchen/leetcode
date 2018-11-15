class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count intput & output itself) */
	ListNode* partition(ListNode* head, int x) {
		ListNode pre0(0), pre1(0);
		auto l1 = &pre0, l2 = &pre1;
		while (head)
			if (head->val < x)
				l1->next = head, l1 = l1->next, head = head->next;
			else
				l2->next = head, l2 = l2->next, head = head->next;
		l1->next = pre1.next, l2->next = NULL;
		return pre0.next;
	}
};
