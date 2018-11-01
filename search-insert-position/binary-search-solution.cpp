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
	int searchInsert(const vector<int>& nums, int target) {
		return lowestTrue(nums.begin(), nums.end(), [&](auto it) {
			return *it >= target;
		}) - nums.begin();
	}
};
