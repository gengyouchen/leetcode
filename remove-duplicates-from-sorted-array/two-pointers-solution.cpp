class Solution {
public:
	/* time: O(n), space: O(1) */
	int removeDuplicates(vector<int>& nums) {
		auto last = nums.begin();
		for (auto it = nums.begin(); it != nums.end(); ++it)
			if (last == nums.begin() || *(last - 1) != *it)
				*last++ = *it;
		return distance(nums.begin(), last);
	}
};
