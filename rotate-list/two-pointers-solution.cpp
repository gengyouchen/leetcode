class Solution {
public:
	/* time: O(length of linked list), space: O(1) */
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || k == 0)
			return head;

		auto first = head, second = head;
		int i;
		for (i = 0; (i < k) && first->next; ++i)
			first = first->next;
		if (i < k)
			return rotateRight(head, k % (i + 1));
		while (first->next)
			first = first->next, second = second->next;

		first->next = head, head = second->next, second->next = NULL;
		return head;
	}
};
