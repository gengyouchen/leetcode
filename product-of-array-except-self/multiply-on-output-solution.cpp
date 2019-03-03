class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<int> productExceptSelf(const vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n);
		for (int i = 0, prod = 1; i < n; ++i)
			ans[i] = prod, prod *= nums[i];
		for (int i = n - 1, prod = 1; i >= 0; --i)
			ans[i] *= prod, prod *= nums[i];
		return ans;
	}
};
