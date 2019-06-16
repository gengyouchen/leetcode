class Solution {
public:
	/*
	 * time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself),
	 * assuming introselect doesn't fall back to the median of medians, which is O(log(n)) space
	 */
	static int findKthLargest(vector<int>& nums, int k) {
		const auto it = nums.begin() + (k - 1);
		nth_element(nums.begin(), it, nums.end(), greater<int>());
		return *it;
	}
};
