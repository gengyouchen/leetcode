class Solution {
public:
	/* time: O(n), space: O(1) */
	bool hasCycle(const ListNode *head) {
		if (!head || !head->next)
			return false;

		const ListNode *fast = head->next, *slow = head;
		while (fast != slow) {
			if (!fast->next || !fast->next->next)
				return false;
			fast = fast->next->next, slow = slow->next;
		}
		return true;
	}
};
