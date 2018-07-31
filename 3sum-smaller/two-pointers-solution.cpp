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
	/* time: O(n^2), extra space: O(1) (i.e. does not count in input itself) */
	int threeSumSmaller(vector<int>& nums, int target) {
		int ans = 0;
		sort(nums.begin(), nums.end());
		for (auto it = nums.begin(); it != nums.end(); ++it)
			ans += sortedTwoSumSmaller(nums.begin(), it, target - *it);
		return ans;
	}
};
