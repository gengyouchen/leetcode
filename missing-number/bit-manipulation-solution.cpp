class Solution {
public:
	/* time: O(n), space: O(1) */
	int missingNumber(const vector<int>& nums) {
		const int n = nums.size();
		int all = 0, given = 0;
		for (int num = 0; num <= n; ++num)
			all ^= num;
		for (int num : nums)
			given ^= num;
		return all ^ given;
	}
};
