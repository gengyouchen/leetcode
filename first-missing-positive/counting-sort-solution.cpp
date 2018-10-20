class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
			while (nums[i] != (i + 1)) {
				const int j = nums[i] - 1;
				if (j < 0 || j >= nums.size() || nums[i] == nums[j])
					break;
				swap(nums[i], nums[j]);
			}
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};
