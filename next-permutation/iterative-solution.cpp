class Solution {
public:
	/* time: O(n), space: O(1) */
	void nextPermutation(vector<int>& nums) {
		auto it = nums.end() - 1;
		while (it != nums.begin() && *(it - 1) >= *it)
			--it;
		/*
		 * Now, sub-permutation [it, it + 1, it + 2, ..., nums.end() - 1] is
		 * the greatest permutation of itself (i.e. sorted in descending order)
		 */

		if (it != nums.begin()) {
			auto curr = it - 1;
			auto next = nums.end() - 1;
			while (*next <= *curr)
				--next;
			iter_swap(curr, next);
		}
		reverse(it, nums.end());
	}
};
