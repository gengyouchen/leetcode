class Solution {
public:
	/* time: O(n), space: O(n) */
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> num2index;
		for (int i = 0; i < nums.size(); i++) {
			auto complement = num2index.find(target - nums[i]);
			if (complement != num2index.end())
				return {complement->second, i};
			num2index[nums[i]] = i;
		}
		return {nums.size(), nums.size()}; /* Not found */
	}
};
