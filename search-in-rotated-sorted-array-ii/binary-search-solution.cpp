class Solution {
public:
	/* time: O(n), space: O(1) */
	bool search(const vector<int>& nums, int target) {
		auto first = nums.begin(), last = nums.end();
		while (last - first > 1 && *first == *(last - 1)) {
			if (*first == target)
				return true;
			++first, --last;
		}

		auto it = lower_bound(first, last, target, [&](int a, int b) {
			if (*first > *(last - 1))
				if (target > *first) {
					if (a <= *(last - 1) && b <= *(last - 1))
						return false; /* let a = b = INFINITY, so a < b is false */
					else if (a <= *(last - 1))
						return false; /* let a = INFINITY, so a < b is false */
					else if (b <= *(last - 1))
						return true; /* let b = INFINITY, so a < b is true */
				} else {
					if (a >= *first && b >= *first)
						return false; /* let a = b = -INFINITY, so a < b is false */
					else if (a >= *first)
						return true; /* let a = -INFINITY, so a < b is true */
					else if (b >= *first)
						return false; /* let b = -INFINITY, so a < b is false */
				}
			return a < b;
		});
		return (it != last) && (*it == target);
	}
};
