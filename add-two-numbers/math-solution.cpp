class Solution {
public:
	/* time: O(max(m, n)), space: O(1) auxiliary (i.e. does not count output itself) */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ans = NULL, *curr = NULL;
		bool carry = false;

		while (carry || l1 || l2) {
			int digit = carry ? 1 : 0;
			if (l1)
				digit += l1->val, l1 = l1->next;
			if (l2)
				digit += l2->val, l2 = l2->next;

			carry = (digit >= 10);
			if (carry)
				digit -= 10;

			if (curr)
				curr = curr->next = new ListNode(digit);
			else
				ans = curr = new ListNode(digit);
		}
		return ans;
	}
};
