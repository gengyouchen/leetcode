class Solution {
public:
	/* time: O(n), space: O(n) */
	RandomListNode *copyRandomList(const RandomListNode *head) {
		if (!head)
			return NULL;

		unordered_map<const RandomListNode*, RandomListNode*> in2out;
		for (auto in = head; in; in = in->next)
			in2out[in] = new RandomListNode(in->label);

		for (const auto& it : in2out) {
			auto in = it.first;
			auto out = it.second;
			if (in->next)
				out->next = in2out[in->next];
			if (in->random)
				out->random = in2out[in->random];
		}
		return in2out[head];
	}
};
