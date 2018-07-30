class Solution {
private:
	template <class I, class T, class F>
	void twoSumSorted(I first, I last, T target, F found) {
		while (last - first > 1) {
			T sum = *first + *(last - 1);
			if (sum < target)
				++first;
			else if (sum > target)
				--last;
			else
				found(first, --last);
		}
	}
public:
	/* time: O(n*log(n)), extra space: O(1) (i.e. does not count input & output) */
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (auto z = nums.begin(); z != nums.end(); ++z) {
			if (z == nums.end() - 1 || *z != *(z + 1))
				twoSumSorted(nums.begin(), z, -*z, [&](auto x, auto y) {
					if (ans.empty() || ans.back()[0] != *x || ans.back()[1] != *y)
						ans.push_back({*x, *y, *z});
				});
		}
		return ans;
	}
};
