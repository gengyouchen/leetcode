class Solution {
private:
	typedef vector<int>::iterator I;
	typedef function<void(I, I)> F;
public:
	/*
	 * time: O(n * (2 ^ n)), space: O(n) auxiliary (i.e. does not count input & output itself),
	 * where n = len(nums)
	 */
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> buf;
		F backtrack = [&](auto first, auto last) {
			ans.push_back(buf);
			for (auto it = first; it != last; ++it) {
				if (it != first && *it == *(it - 1))
					continue; /* skip duplicates */
				buf.push_back(*it);
				backtrack(it + 1, last);
				buf.pop_back();
			}
		};
		backtrack(nums.begin(), nums.end());
		return ans;
	}
};
