class Solution {
public:
	/* time: O(log(n)), space: O(1) */
	int searchInsert(const vector<int>& nums, int target) {
		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};
