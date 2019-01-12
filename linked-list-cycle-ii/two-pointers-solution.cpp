class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head)
			return NULL;
		/*
		 * Key Observation:
		 * In LeetCode 141 - Linked List Cycle,
		 * when the fast pointer meets the slow pointer,
		 * the # of steps we've walked should be an integer multiple of the cycle's length.
		 *
		 * <Proof>
		 * Assume the cycle begins at k-th nodes, and the cycle's length is c.
		 * If the fast pointer meets the slow pointer at step n,
		 * n = k + (c - k % c)
		 * Therefore, n % c = 0 (Q.E.D.)
		 */
		auto fast = head, slow = head;
		do {
			if (!fast->next || !fast->next->next)
				return NULL;
			fast = fast->next->next, slow = slow->next;
		} while (fast != slow);

		/*
		 * Therefore,
		 * if we walks simultaneously from the meeting point and from the head,
		 * we will definitely meet at the beginning of the cycle first
		 */
		while (head != slow)
			head = head->next, slow = slow->next;
		return head;
	}
};
