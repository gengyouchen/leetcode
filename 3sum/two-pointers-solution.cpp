class Solution {
private:
	template <class I, class T, class F>
	void sortedTwoSum(I first, I last, T target, F found) {
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
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<vector<int>> threeSum(vector<int>& nums) {
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (auto z = nums.begin(); z != nums.end(); ++z) {
			if (z != nums.end() - 1 && *z == *(z + 1))
				continue; /* skip duplicates */
			int complement = -*z;
			sortedTwoSum(nums.begin(), z, complement, [&](auto x, auto y) {
				if (!ans.empty() && ans.back()[0] == *x && ans.back()[1] == *y)
					return; /* skip duplicates */
				ans.push_back({*x, *y, *z});
			});
		}
		return ans;
	}
};
