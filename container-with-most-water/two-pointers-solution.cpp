class Solution {
public:
	/*
	 * time: O(n), space: O(1)
	 *
	 * <Proof>
	 * For a sub-problem [L, R], assuming h[L] < h[R] without loss of generality...
	 * We don't know whether line L is included in the optima solution or not:
	 *
	 * Case 1: If line L is included in the optima solution,
	 *         the max area of this sub-problem can only be h[L] * (R-L)
	 *
	 * Case 2: If line L is NOT included in the optima solution,
	 *         we only need to consider the sub-problem [L+1, R]
	 *
	 * Both case 1 & 2 are considered, so this can guarantee the correct answer
	 */
	int maxArea(vector<int>& height) {
		int ans = 0, L = 0, R = height.size() - 1;
		while (L < R)
			if (height[L] < height[R])
				ans = max(ans, height[L] * (R - L)), L++;
			else
				ans = max(ans, height[R] * (R - L)), R--;
		return ans;
	}
};
