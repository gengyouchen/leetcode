class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *buf = NULL;
		while (head) {
			auto x = head; /* x = head.top(); */
			head = head->next; /* head.pop(); */
			x->next = buf, buf = x; /* buf.push(x); */
		}
		return buf;
	}
};
