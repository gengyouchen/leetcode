class Solution {
private:
	template <class T, class F>
	T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
public:
	/* time: O(log(n)), space: O(1) */
	vector<int> searchRange(const vector<int>& nums, int target) {
		auto L = nums.begin(), R = nums.end();
		L = lowestTrue(L, R, [&](auto it) { return *it >= target; });
		R = lowestTrue(L, R, [&](auto it) { return *it > target; });
		if (L == R)
			return {-1, -1};
		return {distance(nums.begin(), L), distance(nums.begin(), R - 1)};
	}
};
