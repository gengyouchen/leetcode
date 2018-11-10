class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode dummy(0);
		auto out = &dummy;

		while (head) {
			ListNode *buf = NULL;
			int bufSize = 0;

			/* try to move identical elements into buf */
			while (!buf || (head && (buf->val == head->val))) {
				auto x = head; /* x = head.top() */
				head = head->next; /* head.pop() */
				x->next = buf, buf = x, ++bufSize; /* buf.push(x) */
			}

			if (bufSize == 1)
				out->next = buf, out = buf;
			else
				while (buf) {
					auto x = buf; /* x = buf.top() */
					buf = buf->next; /* buf.pop() */
					delete x;
				}
		}
		return dummy.next;
	}
};
