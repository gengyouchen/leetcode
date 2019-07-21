class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static ListNode* oddEvenList(ListNode* head) {
		ListNode evenHead(0), oddHead(0);
		auto even = &evenHead, odd = &oddHead;

		while (head) {
			auto x = head; /* x = head.top() */
			head = head->next; /* head.pop() */

			even->next = x, even = even->next;

			if (head) {
				auto y = head; /* y = head.top() */
				head = head->next; /* head.pop() */

				odd->next = y, odd = odd->next;
			}
		}
		even->next = oddHead.next, odd->next = NULL;
		return evenHead.next;
	}
};
