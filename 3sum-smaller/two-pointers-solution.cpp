class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input itself) */
	static int threeSumSmaller(vector<int>& nums, int target) {
		const int n = nums.size();
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());

		auto twoSumSmaller = [&](int L, int R, int target) {
			int count = 0;
			while (L < R) {
				if (nums[L] + nums[R] < target)
					count += R - L, ++L;
				else
					--R;
			}
			return count;
		};

		int ans = 0;
		for (int i = 2; i < n; ++i)
			ans += twoSumSmaller(0, i - 1, target - nums[i]);
		return ans;
	}
};
