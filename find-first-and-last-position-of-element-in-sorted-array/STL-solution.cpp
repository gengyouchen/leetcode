class Solution {
public:
	/* time: O(log(n)), space: O(1) */
	vector<int> searchRange(const vector<int>& nums, int target) {
		auto p = equal_range(nums.begin(), nums.end(), target);
		if (p.first == p.second)
			return {-1, -1};
		return {distance(nums.begin(), p.first), distance(nums.begin(), p.second - 1)};
	}
};
