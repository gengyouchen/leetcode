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
	int findPeakElement(const vector<int>& nums) {
		const int n = nums.size();
		auto cond = [&](int i) { return (i == n - 1) || (nums[i] >= nums[i + 1]); };
		return lowestTrue(0, n, cond);
	}
};
