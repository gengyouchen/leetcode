class Solution {
public:
	/* time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());
		return nums;
	}
};
