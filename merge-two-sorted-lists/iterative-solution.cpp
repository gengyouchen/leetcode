class Solution {
public:
	/* time: O(m+n), space: O(1) */
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
};
