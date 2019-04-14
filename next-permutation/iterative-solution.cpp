class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static void nextPermutation(vector<int>& nums) {
		const auto curr = is_sorted_until(nums.rbegin(), nums.rend());
		/*
		 * The sub-permutation { *(curr-1), *(curr-2), *(curr-3), ..., *nums.rbegin() }
		 * is already the greatest possible sub-permutation of itself
		 */
		if (curr != nums.rend()) {
			auto cond = [&](int num) { return num > *curr; };
			const auto next = find_if(nums.rbegin(), nums.rend(), cond);
			iter_swap(curr, next);
		}
		reverse(nums.rbegin(), curr);
	}
};
