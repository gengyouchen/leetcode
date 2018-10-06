class Solution {
private:
	void removeNext(ListNode* head) {
		auto target = head->next;
		head->next = target->next;
		delete target;
	}
public:
	/* time: O(length of linked list), space: O(1) */
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy(0);
		dummy.next = head;
		auto first = &dummy, second = &dummy;
		for (int i = 0; i < n; ++i)
			first = first->next;
		while (first->next)
			first = first->next, second = second->next;
		removeNext(second);
		return dummy.next;
	}
};
