class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(0);
		auto out = &dummy;
		while (head) {
			auto x = head; /* x = head.top() */
			head = head->next; /* head.pop() */
			if (x->val != val)
				out->next = x, out = out->next;
		}
		out->next = NULL;
		return dummy.next;
	}
};
