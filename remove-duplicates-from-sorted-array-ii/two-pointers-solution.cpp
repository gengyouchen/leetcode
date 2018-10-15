class Solution {
public:
	/* time: O(n), space: O(1) */
	int removeDuplicates(vector<int>& nums) {
		auto last = nums.begin();
		int nAppeared = 0;
		for (auto it = nums.begin(); it != nums.end(); ++it)
			if (last == nums.begin() || *(last - 1) != *it)
				*last++ = *it, nAppeared = 1;
			else if (nAppeared < 2)
				*last++ = *it, ++nAppeared;
		return distance(nums.begin(), last);
	}
};
