class Solution {
public:
	/* time: O(n), space: O(1) */
	int singleNumber(const vector<int>& nums) {
		int ans = 0;
		for (int num : nums)
			ans ^= num;
		return ans;
	}
};
