class Solution {
private:
	template <class I, class T, class F>
	void traceTwoSumSorted(I first, I last, T target, F trace) {
		while (last - first > 1) {
			T sum = *first + *(last - 1);
			trace(first, last - 1);
			if (sum < target)
				++first;
			else
				--last;
		}
	}
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans, distance = INT_MAX;
		sort(nums.begin(), nums.end());
		for (auto z = nums.begin(); z != nums.end(); ++z)
			traceTwoSumSorted(nums.begin(), z, target - *z, [&](auto x, auto y) {
				int curr = abs(*x + *y + *z - target);
				if (curr < distance)
					distance = curr, ans = *x + *y + *z;
			});
		return ans;
	}
};
