class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void rotate(vector<int>& nums, int k) {
		const int n = nums.size();
		k %= n;
		auto mid = nums.begin() + k;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), mid);
		reverse(mid, nums.end());
	}
};
