class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void connect(TreeLinkNode *root) {
		while (root) {
			TreeLinkNode dummy(0);
			auto in = root, out = &dummy;
			while (in) {
				if (in->left)
					out->next = in->left, out = out->next;
				if (in->right)
					out->next = in->right, out = out->next;
				in = in->next;
			}
			root = dummy.next;
		}
	}
};
