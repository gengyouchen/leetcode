// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	/* time: O(n), space: O(1) */
	static int findCelebrity(int n) {
		if (n <= 0)
			return -1;
		/*
		 * If knows(X, Y), then X is not a celebrity.
		 * Otherwise, Y is not a celebrity.
		 *
		 * Each knows(X, Y) API call can eliminate one candidates.
		 */
		int L = 0, R = n - 1;
		while (L < R) {
			if (knows(L, R))
				++L;
			else
				--R;
		}

		/* Verify the last candidate */
		const int candidate = L;
		for (int i = 0; i < n; ++i) {
			if (i != candidate) {
				if (knows(candidate, i) || !knows(i, candidate))
					return -1;
			}
		}
		return candidate;
	}
};
