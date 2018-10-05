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
	/* time: O(n^3), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (auto w = nums.begin(); w != nums.end(); ++w) {
			if (w + 1 != nums.end() && *w == *(w + 1))
				continue; /* skip duplicates */
			for (auto z = nums.begin(); z != w; ++z) {
				if (z + 1 != w && *z == *(z + 1))
					continue; /* skip duplicates */
				int complement = target - (*z + *w);
				sortedTwoSum(nums.begin(), z, complement, [&](auto x, auto y) {
					vector<int> quadruplets {*x, *y, *z, *w};
					if (!ans.empty() && equal(ans.back().begin(), ans.back().end(), quadruplets.begin()))
						return; /* skip duplicates */
					ans.push_back(quadruplets);
				});
			}
		}
		return ans;
	}
};
