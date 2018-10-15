class Solution {
public:
	/* time: O(n), space: O(1) */
	int removeElement(vector<int>& nums, int val) {
		auto it = nums.begin(), last = nums.end();
		while (it != last) {
			if (*it == val)
				*it = *--last;
			else
				++it;
		}
		return distance(nums.begin(), last);
	}
};
