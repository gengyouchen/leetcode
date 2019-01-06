class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)
			return NULL;

		for (auto in = head; in; in = in->next->next) {
			auto out = new RandomListNode(in->label);
			out->next = in->next, in->next = out;
		}

		for (auto in = head; in; in = in->next->next) {
			auto out = in->next;
			if (in->random)
				out->random = in->random->next;
		}

		auto ans = head->next;
		for (auto in = head; in; in = in->next) {
			auto out = in->next;
			in->next = in->next->next;
			if (out->next)
				out->next = out->next->next;
		}
		return ans;
	}
};
