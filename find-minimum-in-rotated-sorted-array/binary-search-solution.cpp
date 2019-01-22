class Solution {
public:
	/* time: O(log(n)), space: O(1) */
	int findMin(const vector<int>& nums) {
		/*
		 * Use the same idea as LeetCode 33 - Search in Rotated Sorted Array
		 *
		 * For example,
		 * if the input array is [88, 91, 105, 112, 12, 19, 33, 64, 69, 75],
		 * in our comparison function, we pretends all the elements >= 88 are -INFINITY
		 *
		 * Now, the array becomes [-INF, -INF, -INF, -INF, 12, 19, 33, 64, 69, 75].
		 * Because this array is not rotated, we can directly use STL binary search.
		 */
		auto comp = [&](int a, int b) {
			if (nums.front() > nums.back()) {
				if (a >= nums.front() && b >= nums.front())
					return false; /* let a = b = -INFINITY, so a < b is false */
				else if (a >= nums.front())
					return true; /* let a = -INFINITY, so a < b is true */
				else if (b >= nums.front())
					return false; /* let b = -INFINITY, so a < b is false */
			}
			return a < b;
		};
		return *lower_bound(nums.begin(), nums.end(), INT_MIN, comp);
	}
};
