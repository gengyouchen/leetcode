class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy(0);
		while (head) {
			auto x = head; /* x = head.top() */
			head = head->next; /* head.pop() */

			auto out = &dummy;
			while (out->next && (x->val > out->next->val))
				out = out->next;
			x->next = out->next, out->next = x;
		}
		return dummy.next;
	}
};
