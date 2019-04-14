class Solution {
private:
	typedef vector<int>::iterator I;
	typedef function<void(I)> F;
public:
	/* time: O(n * n!), space: O(n) auxiliary (i.e. does not count output itself) */
	static vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		F backtrack = [&](auto curr) {
			if (curr == nums.end()) {
				ans.push_back(nums);
			} else {
				backtrack(curr + 1);
				for (auto next = curr + 1; next != nums.end(); ++next)
					iter_swap(curr, next), backtrack(curr + 1), iter_swap(curr, next);
			}
		};
		backtrack(nums.begin());
		return ans;
	}
};
