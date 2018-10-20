class Solution {
private:
	/*
	 * Modified from LeetCode 31 - Next Permutation:
	 * If there's no next greater permutation, just stop.
	 */
	bool nextPermutation(vector<int>& nums) {
		bool isLastPermutation = false;
		auto it = nums.end() - 1;
		while (it != nums.begin() && *(it - 1) >= *it)
			--it;
		/*
		 * Now, sub-permutation [it, it + 1, it + 2, ..., nums.end() - 1] is
		 * the greatest permutation of itself (i.e. sorted in descending order)
		 */
		if (it == nums.begin())
			return false; /* there's no next greater permutation */

		auto curr = it - 1;
		auto next = nums.end() - 1;
		while (*next <= *curr)
			--next;
		iter_swap(curr, next);

		reverse(it, nums.end());
		return true; /* succeed */
	}
public:
	/* time: O(n * n!), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());

		vector<vector<int>> ans;
		do
			ans.push_back(nums);
		while (nextPermutation(nums));
		return ans;
	}
};
