class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void wiggleSort(vector<int>& nums) {
		const int n = nums.size();
		for (int i = 0; i < n - 1; ++i) {
			if (i % 2) {
				assert(nums[i - 1] <= nums[i]); /* invariant */
				if (nums[i] < nums[i + 1])
					swap(nums[i], nums[i + 1]);
			} else {
				assert(i == 0 || nums[i - 1] >= nums[i]); /* invariant */
				if (nums[i] > nums[i + 1])
					swap(nums[i], nums[i + 1]);
			}
		}
	}
};
