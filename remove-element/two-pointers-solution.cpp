class Solution {
public:
	/* time: O(n), space: O(1) */
	int removeElement(vector<int>& nums, int val) {
		auto it = nums.begin(), removed = nums.end();
		while (it != removed) {
			if (*it == val)
				*it = *--removed;
			else
				++it;
		}
		return distance(nums.begin(), removed);
	}
};
