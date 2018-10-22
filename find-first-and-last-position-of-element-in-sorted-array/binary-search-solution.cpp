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
	vector<int> searchRange(const vector<int>& nums, int target) {
		auto L = nums.begin(), R = nums.end();
		L = findFirstTrue(L, R, [&](auto it) { return *it >= target; });
		R = findFirstTrue(L, R, [&](auto it) { return *it > target; });
		if (L == R)
			return {-1, -1};
		return {distance(nums.begin(), L), distance(nums.begin(), R - 1)};
	}
};
