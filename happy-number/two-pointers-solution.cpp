class Solution {
public:
	/*
	 * time: O(log*n), space: O(1), where O(log*n) is the "iterated logarithm" of n
	 * See https://en.wikipedia.org/wiki/Iterated_logarithm
	 */
	bool isHappy(int n) {
		/*
		 * <Observation>
		 * For every number n, after some iterations, it will finally loop.
		 *
		 * <Proof>
		 * If log(old n) >= 3 (i.e. it has >= 4 digits), new n will become smaller
		 * because (new n) < (9 * 9) * log(old n)
		 *
		 * If log(old n) < 3 (i.e. it has < 4 digits), log(new n) will still < 3
		 * because even if old n is 999, the new n is (9 * 9) * log(999) < 1000
		 *
		 * <Solution>
		 * If we treat the number in each iteration as nodes in a linked list,
		 * this is exactly the same problem as LeetCode 142 - Linked List Cycle II
		 *
		 * By using the two pointers method, we can achieve O(1) space
		 */
		auto next = [](int p) {
			int ans = 0;
			while (p)
				ans += (p % 10) * (p % 10), p /= 10;
			return ans;
		};
		auto detectCycle = [&](long p) -> long {
			long fast = p, slow = p;
			do {
				if (!next(fast) || !next(next(fast)))
					return 0;
				fast = next(next(fast)), slow = next(slow);
			} while (fast != slow);

			while (p != slow)
				p = next(p), slow = next(slow);
			return p;
		};
		return detectCycle(n) == 1;
	}
};
