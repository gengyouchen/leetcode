class Solution {
private:
	typedef function<void()> F;
public:
	/* time: O(n * n!), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> permute(const vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> buf;
		vector<bool> taken(nums.size(), false);
		F backtrack = [&]() {
			if (buf.size() == nums.size())
				ans.push_back(buf);
			else
				for (int i = 0; i < nums.size(); ++i)
					if (!taken[i]) {
						taken[i] = true;
						buf.push_back(nums[i]);
						backtrack();
						buf.pop_back();
						taken[i] = false;
					}
		};
		backtrack();
		return ans;
	}
};
