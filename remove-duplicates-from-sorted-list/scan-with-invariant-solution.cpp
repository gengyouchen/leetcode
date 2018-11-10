class Solution {
private:
	void removeNext(ListNode* head) {
		auto target = head->next;
		head->next = target->next;
		delete target;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	ListNode* deleteDuplicates(ListNode* head) {
		auto out = head;
		while (head) {
			while (head->next && head->val == head->next->val)
				removeNext(head);
			assert(!head->next || head->val != head->next->val); /* invariant */
			head = head->next;
		}
		return out;
	}
};
