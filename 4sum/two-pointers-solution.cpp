class Solution {
public:
	/* time: O(n^3), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<vector<int>> fourSum(vector<int>& nums, int target) {
		const int n = nums.size();
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());

		auto twoSum = [&](int L, int R, int target, auto found) {
			while (L < R) {
				const int sum = nums[L] + nums[R];
				if (sum < target)
					++L;
				else if (sum > target)
					--R;
				else
					found(L, R), --R;
			}
		};

		vector<vector<int>> ans;
		for (int i = 3; i < n; ++i) {
			if (i == n - 1 || nums[i] != nums[i + 1]) {
				for (int j = 2; j < i; ++j) {
					if (j == i - 1 || nums[j] != nums[j + 1]) {
						auto found = [&](int L, int R) {
							if (ans.empty() || ans.back()[0] != nums[L] || ans.back()[1] != nums[R] || ans.back()[2] != nums[j])
								ans.push_back({nums[L], nums[R], nums[j], nums[i]});
						};
						twoSum(0, j - 1, target - nums[i] - nums[j], found);
					}
				}
			}
		}
		return ans;
	}
};
