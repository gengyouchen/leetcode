class Solution {
public:
	/* time: O(n), space: O(1) */
	int minSubArrayLen(int s, const vector<int>& nums) {
		int sum = 0, ans = INT_MAX;
		/*
		 * Notice that:
		 * This is the easier version of LeetCode 862. Shortest Subarray with Sum at Least K
		 * In LeetCode 862, num can also be negative, which makes the two pointers solution fail
		 * But LeetCode 862 can still be solved in O(n) time by using deque to maintain candidates
		 * See https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solution/
		 *
		 * In this problem, because all num are positive, we just use the two pointers solution
		 * This can achieve O(n) time and O(1) space
		 */
		auto L = nums.begin();
		for (auto R = nums.begin(); R != nums.end(); ++R) {
			sum += *R;
			while (sum >= s)
				ans = min(ans, (int)distance(L, R + 1)), sum -= *L++;
		}
		return (ans == INT_MAX) ? 0 : ans;
	}
};
