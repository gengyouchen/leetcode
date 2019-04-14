class Solution {
private:
	/*
	 * Modified from LeetCode 31 - Next Permutation:
	 * If there's no next greater permutation, just stop.
	 */
	static bool nextPermutation(vector<int>& nums) {
		const auto curr = is_sorted_until(nums.rbegin(), nums.rend());
		/*
		 * The sub-permutation { *(curr-1), *(curr-2), *(curr-3), ..., *nums.rbegin() }
		 * is already the greatest possible sub-permutation of itself
		 */
		if (curr == nums.rend())
			return false;

		auto cond = [&](int num) { return num > *curr; };
		const auto next = find_if(nums.rbegin(), nums.rend(), cond);
		iter_swap(curr, next), reverse(nums.rbegin(), curr);
		return true;
	}
public:
	/* time: O(n * n!), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		make_heap(nums.begin(), nums.end()), sort_heap(nums.begin(), nums.end());
		do {
			ans.push_back(nums);
		} while (nextPermutation(nums));
		return ans;
	}
};
