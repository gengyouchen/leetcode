class Solution {
public:
	/* time: O(n), space: O(1) */
	bool hasCycle(ListNode *head) {
		if (!head)
			return false;
		auto fast = head, slow = head;
		do {
			if (!fast->next || !fast->next->next)
				return false;
			fast = fast->next->next, slow = slow->next;
		} while (fast != slow);
		return true;
	}
};
