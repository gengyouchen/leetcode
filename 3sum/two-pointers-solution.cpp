class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<vector<int>> threeSum(vector<int>& nums) {
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
		for (int i = 2; i < n; ++i) {
			if (i == n - 1 || nums[i] != nums[i + 1]) {
				auto found = [&](int L, int R) {
					if (ans.empty() || ans.back()[0] != nums[L] || ans.back()[1] != nums[R])
						ans.push_back({nums[L], nums[R], nums[i]});
				};
				twoSum(0, i - 1, -nums[i], found);
			}
		}
		return ans;
	}
};
