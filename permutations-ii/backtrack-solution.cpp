class Solution {
private:
	typedef vector<int>::iterator I;
	typedef function<void(I)> F;
public:
	/* time: O(n * n!), space: O(n) auxiliary (i.e. does not count output itself) */
	static vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		F backtrack = [&](auto curr) {
			if (curr == nums.end()) {
				ans.push_back(nums);
			} else {
				backtrack(curr + 1);
				/* Loop Invariant: *(curr+1) <= *(curr+2) <= *(curr+3) <= ... */
				for (auto next = curr + 1; next != nums.end(); ++next) {
					if (*next > *curr)
						iter_swap(curr, next), backtrack(curr + 1);
				}
				rotate(curr, curr + 1, nums.end()); /* rollback */
			}
		};
		sort(nums.begin(), nums.end());
		backtrack(nums.begin());
		return ans;
	}
};
