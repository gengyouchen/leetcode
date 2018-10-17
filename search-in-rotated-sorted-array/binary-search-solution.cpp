class Solution {
public:
	/* time: O(log(n)), space: O(1) */
	int search(const vector<int>& nums, int target) {
		auto it = lower_bound(nums.begin(), nums.end(), target, [&](int a, int b) {
			if (nums.front() > nums.back())
				if (target > nums.front()) {
					if (a <= nums.back() && b <= nums.back())
						return false; /* let a = b = INFINITY, so a < b is false */
					else if (a <= nums.back())
						return false; /* let a = INFINITY, so a < b is false */
					else if (b <= nums.back())
						return true; /* let b = INFINITY, so a < b is true */
				} else {
					if (a >= nums.front() && b >= nums.front())
						return false; /* let a = b = -INFINITY, so a < b is false */
					else if (a >= nums.front())
						return true; /* let a = -INFINITY, so a < b is true */
					else if (b >= nums.front())
						return false; /* let b = -INFINITY, so a < b is false */
				}
				return a < b;
		});
		return (it != nums.end() && *it == target) ? distance(nums.begin(), it) : -1;
	}
};
