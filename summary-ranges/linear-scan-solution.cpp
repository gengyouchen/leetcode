class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<string> summaryRanges(const vector<int>& nums) {
		if (nums.empty())
			return {};

		vector<string> ans;
		auto output = [&](int from, int to) {
			if (from < to)
				ans.push_back(to_string(from) + "->" + to_string(to));
			else if (from == to)
				ans.push_back(to_string(from));
		};

		int lower = nums.front(), upper = nums.front();
		for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
			if (*it == upper + 1)
				upper = *it;
			else
				output(lower, upper), lower = upper = *it;
		}
		output(lower, upper);
		return ans;
	}
};
