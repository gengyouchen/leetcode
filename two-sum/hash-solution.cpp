class Solution {
public:
	/* time: O(n), space: O(n) */
	static vector<int> twoSum(const vector<int>& nums, int target) {
		const int n = nums.size();
		unordered_map<int, int> num2index;
		for (int i = 0; i < n; ++i) {
			auto complement = num2index.find(target - nums[i]);
			if (complement != num2index.end())
				return {complement->second, i};
			num2index[nums[i]] = i;
		}
		return {};
	}
};
