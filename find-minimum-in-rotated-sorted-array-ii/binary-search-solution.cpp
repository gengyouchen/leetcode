class Solution {
public:
	/* time: O(n), space: O(1) */
	int findMin(const vector<int>& nums) {
		/*
		 * Use the same idea as LeetCode 81 - Search in Rotated Sorted Array II
		 *
		 * For example,
		 * if the input array is [1, 1, 1, ..., 1, 1, 1, 2, 2, 2, 3, 0, 0, 1, 1, 1, ..., 1, 1, 1],
		 * which means the first number equals the last number,
		 * there's no way to do binary search.
		 *
		 * Therefore, before the binary search,
		 * We need to reduce it to a sub-array such that the first number is NOT equal to the last number.
		 * In the above example,
		 * the input array is reduced to a sub-array [2, 2, 2, 3, 0, 0, 1, 1, 1, ..., 1, 1, 1].
		 */
		auto first = nums.begin(), last = nums.end();
		while (last - first > 1 && *first == *(last - 1))
			++first;

		/*
		 * Use the same idea as LeetCode 153 - Find Minimum in Rotated Sorted Array
		 *
		 * In the above example,
		 * we can pretends all the elements >= 2 are -INFINITY in our comparison function.
		 *
		 * Now, the sub-array becomes [-INF, -INF, -INF, -INF, 0, 0, 1, 1, 1, ..., 1, 1, 1].
		 * Because this sub-array is not rotated, we can directly use STL binary search.
		 */
		auto comp = [&](int a, int b) {
			if (*first > *(last - 1)) {
				if (a >= *first && b >= *first)
					return false; /* let a = b = -INFINITY, so a < b is false */
				else if (a >= *first)
					return true; /* let a = -INFINITY, so a < b is true */
				else if (b >= *first)
					return false; /* let b = -INFINITY, so a < b is false */
			}
			return a < b;
		};
		return *lower_bound(first, last, INT_MIN, comp);
	}
};
