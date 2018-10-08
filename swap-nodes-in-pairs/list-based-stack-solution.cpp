class Solution {
public:
	/* time: O(n), space: O(1) */
	ListNode* swapPairs(ListNode* head) {
		ListNode dummy(0);
		auto out = &dummy;

		while (head) {
			auto nextOut = head;

			/* move 2 elements into buf */
			ListNode* buf = NULL;
			for (int i = 0; i < 2 && head; ++i) {
				auto x = head; /* x = head.top() */
				head = head->next; /* head.pop() */
				x->next = buf, buf = x; /* buf.push(x) */
			}

			out->next = buf, out = nextOut;
		}
		return dummy.next;
	}
};
