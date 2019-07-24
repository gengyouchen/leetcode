class Solution {
public:
	/*
	 * time: O(k + log(n)), space: O(1), where k = # of nums
	 *
	 * <Greedy-choice Property>
	 * Consider nums[0 ~ i] form the covered range 1 ~ maxCover.
	 *
	 * If nums[i+1] > maxCover+1, because nums are non-decreasing,
	 * there's no chance to form maxCover+1 anymore.
	 * The only way is to insert a new element X before considering nums[i+1].
	 *
	 * To cover maxCover+1, we can choose the value of X between 1 ~ maxCover+1.
	 * We greedily choose the value of X = maxCover+1.
	 *
	 * <Proof>
	 * Assume there's a global optimal which inserts Y before considering nums[i+1].
	 * If Y < X, we can always replace Y with X without breaking the covered range.
	 * Therefore, X can also yield a global optima solution.
	 */
	static int minPatches(const vector<int>& nums, int n) {
		const int k = nums.size();
		long long maxCover = 0;
		int i = 0, ans = 0;

		while (maxCover < n) {
			if (i < k && nums[i] <= maxCover + 1)
				maxCover += nums[i++];
			else
				++ans, maxCover += maxCover + 1;
		}
		return ans;
	}
};
