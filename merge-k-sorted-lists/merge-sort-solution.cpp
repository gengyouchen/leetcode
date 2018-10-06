class Solution {
private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		auto out = &dummy;
		while (l1 && l2)
			if (l1->val < l2->val)
				out->next = l1, out = out->next, l1 = l1->next;
			else
				out->next = l2, out = out->next, l2 = l2->next;
		if (l1)
			out->next = l1;
		if (l2)
			out->next = l2;
		return dummy.next;
	}
public:
	/* time: O((total # of nodes) * log(# of lists)), space: O(1) */
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;
		int n = lists.size();
		while (n > 1) {
			int out = 0;
			for (int i = 0; i < n; i += 2)
				if (i + 1 < n)
					lists[out++] = mergeTwoLists(lists[i], lists[i + 1]);
				else
					lists[out++] = lists[i];
			n = out;
		}
		return lists[0];
	}
};
