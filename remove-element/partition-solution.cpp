class Solution {
public:
	/* time: O(n), space: O(1) */
	int removeElement(vector<int>& nums, int val) {
		auto last = partition(nums.begin(), nums.end(), [&](auto num) {
			return num != val;
		});
		return distance(nums.begin(), last);
	}
};
