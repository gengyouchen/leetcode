class Solution {
public:
	/* time: O(n), space: O(1) */
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(0);
		auto out = &dummy;

		for (int i = 0; i < m - 1 && head; ++i) {
			auto x = head; /* x = head.top() */
			head = head->next; /* head.pop() */

			out->next = x, out = x;
		}

		if (head) {
			auto nextOut = head;

			/* move (n - m + 1) elements into buf */
			ListNode *buf = NULL;
			for (int i = 0; i < n - m + 1 && head; ++i) {
				auto x = head; /* x = head.top() */
				head = head->next; /* head.pop() */
				x->next = buf, buf = x; /* buf.push(x) */
			}

			out->next = buf, out = nextOut;
		}

		out->next = head, out = NULL;
		return dummy.next;
	}
};
