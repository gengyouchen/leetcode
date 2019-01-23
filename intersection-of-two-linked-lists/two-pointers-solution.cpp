class Solution {
private:
	int countList(const ListNode* head) {
		int len = 0;
		while (head)
			head = head->next, ++len;
		return len;
	}
public:
	/* time: O(n), space: O(1) */
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		const int lenA = countList(headA), lenB = countList(headB);
		if (lenA - lenB > 0) {
			for (int i = 0; i < lenA - lenB; ++i)
				headA = headA->next;
		} else if (lenB - lenA > 0) {
			for (int i = 0; i < lenB - lenA; ++i)
				headB = headB->next;
		}
		while (headA) {
			if (headA == headB)
				return headA;
			headA = headA->next, headB = headB->next;
		}
		return NULL;
	}
};
