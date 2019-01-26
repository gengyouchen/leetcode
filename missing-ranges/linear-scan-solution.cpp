class Solution {
public:
	/* time: O(n * log(abs(upper))), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<string> findMissingRanges(const vector<int>& nums, int lower, int upper) {
		vector<string> ans;
		auto output = [&](int from, int to) {
			if (from < to)
				ans.push_back(to_string(from) + "->" + to_string(to));
			else if (from == to)
				ans.push_back(to_string(from));
		};

		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (*it > lower)
				output(lower, *it - 1);

			if (*it < upper)
				lower = *it + 1;
			else if (*it == upper)
				return ans;
		}
		output(lower, upper);
		return ans;
	}
};
