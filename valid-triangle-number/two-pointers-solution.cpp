class Solution {
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input itself) */
	static int triangleNumber(vector<int>& nums) {
		const int n = nums.size();
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());

		auto twoSumLarger = [&](int L, int R, int target) {
			int count = 0;
			while (L < R) {
				if (nums[L] + nums[R] > target)
					count += R - L, --R;
				else
					++L;
			}
			return count;
		};

		int ans = 0;
		for (int i = 2; i < n; ++i)
			ans += twoSumLarger(0, i - 1, nums[i]);
		return ans;
	}
};
