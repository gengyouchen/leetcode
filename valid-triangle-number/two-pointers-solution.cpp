class Solution {
private:
	template <class I, class T>
	int sortedTwoSumLarger(I first, I last, T target) {
		int ans = 0;
		while (last - first > 1) {
			T sum = *first + *(last - 1);
			if (sum > target)
				ans += --last - first;
			else
				++first;
		}
		return ans;
	}
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input itself) */
	int triangleNumber(vector<int>& nums) {
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());
		int ans = 0;
		for (auto z = nums.begin(); z != nums.end(); ++z)
			/* Apply the triangle inequality */
			ans += sortedTwoSumLarger(nums.begin(), z, *z);
		return ans;
	}
};
