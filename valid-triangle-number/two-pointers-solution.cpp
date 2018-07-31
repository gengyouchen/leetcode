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
	/* time: O(n*log(n)), extra space: O(1) (i.e. does not count in input itself) */
	int triangleNumber(vector<int>& nums) {
		int ans = 0;
		sort(nums.begin(), nums.end());
		for (auto it = nums.begin(); it != nums.end(); ++it)
			ans += sortedTwoSumLarger(nums.begin(), it, *it);
		return ans;
	}
};
