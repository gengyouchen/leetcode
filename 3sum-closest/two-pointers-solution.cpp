class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input itself) */
	static int threeSumClosest(vector<int>& nums, int target) {
		const int n = nums.size();
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());

		auto twoSumClosest = [&](int L, int R, int target) {
			int closest, d = INT_MAX;
			while (L < R) {
				const int sum = nums[L] + nums[R];
				if (abs(sum - target) < d)
					d = abs(sum - target), closest = sum;
				if (sum < target)
					++L;
				else if (sum > target)
					--R;
				else
					break;
			}
			return closest;
		};

		int ans, d = INT_MAX;
		for (int i = 2; i < n; ++i) {
			const int sum = nums[i] + twoSumClosest(0, i - 1, target - nums[i]);
			if (abs(sum - target) < d)
				d = abs(sum - target), ans = sum;
		}
		return ans;
	}
};
