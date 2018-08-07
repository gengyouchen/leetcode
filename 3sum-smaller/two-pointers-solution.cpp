class Solution {
private:
	template <class I, class T>
	int sortedTwoSumSmaller(I first, I last, T target) {
		int ans = 0;
		while (last - first > 1) {
			T sum = *first + *(last - 1);
			if (sum < target)
				ans += last - ++first;
			else
				--last;
		}
		return ans;
	}
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input itself) */
	int threeSumSmaller(vector<int>& nums, int target) {
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());
		int ans = 0;
		for (auto z = nums.begin(); z != nums.end(); ++z) {
			int complement = target - *z;
			ans += sortedTwoSumSmaller(nums.begin(), z, complement);
		}
		return ans;
	}
};
