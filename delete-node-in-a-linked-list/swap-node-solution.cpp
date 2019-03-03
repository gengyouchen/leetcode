class Solution {
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void deleteNode(ListNode* node) {
		auto victim = node->next;
		*node = *victim;
		delete victim;
	}
};
