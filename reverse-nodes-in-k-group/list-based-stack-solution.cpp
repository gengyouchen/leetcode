class Solution {
public:
	/* time: O(n), space: O(1) */
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode dummy(0);
		auto out = &dummy;

		while (head) {
			auto nextOut = head;

			/* try to move k elements into buf */
			ListNode* buf = NULL;
			int bufSize = 0;
			while (head && bufSize < k) {
				auto x = head; /* x = head.top() */
				head = head->next; /* head.pop() */
				x->next = buf, buf = x, ++bufSize; /* buf.push(x) */
			}

			if (bufSize == k) {
				/* succeed (i.e. # of the rest elements >= k) */
				out->next = buf, out = nextOut;
			} else {
				/* failed (i.e. # of the rest elements < k) */
				while (buf) {
					auto x = buf; /* x = buf.top() */
					buf = buf->next; /* buf.pop() */
					x->next = head, head = x; /* head.push(x) */
				}
				out->next = head, head = NULL;
			}
		}
		return dummy.next;
	}
};
