class Solution {
private:
	template <class I, class F>
	I findFirstTrue(I first, I last, F cond) {
		while (first != last) {
			I mid = first + (last - first) / 2;
			if (cond(mid))
				last = mid;
			else
				first = mid + 1;
		}
		return first;
	}
public:
	/* time: O(log(n)), space: O(1) */
	int searchInsert(vector<int>& nums, int target) {
		return findFirstTrue(nums.begin(), nums.end(), [&](auto it) {
			return *it >= target;
		}) - nums.begin();
	}
};
