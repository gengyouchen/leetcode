class Solution {
public:
	/* time: O(n), space: O(1) */
	static int findDuplicate(const vector<int>& nums) {
		/*
		 * <Proof>
		 * Recall the Pigeonhole principle,
		 * if n items are put into m containers, where n > m,
		 * at least one container must contain more than one item.
		 *
		 * <Solution>
		 * If we treat each entry's value as a pointer to other entry's index,
		 * this is exactly the same problem as LeetCode 142 - Linked List Cycle II
		 *
		 * By using the two pointers method, we can achieve O(1) space
		 */
		auto next = [&](int p) { return nums[p]; };
		auto detectCycle = [&](int p) {
			int fast = p, slow = p;
			do {
				if (!next(fast) || !next(next(fast)))
					return 0;
				fast = next(next(fast)), slow = next(slow);
			} while (fast != slow);

			while (p != slow)
				p = next(p), slow = next(slow);
			return p;
		};
		return detectCycle(0);
	}
};
