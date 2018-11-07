class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	int findKthLargest(vector<int>& nums, int k) {
		const auto target = nums.end() - k;
		nth_element(nums.begin(), target, nums.end());
		return *target;
	}
};
